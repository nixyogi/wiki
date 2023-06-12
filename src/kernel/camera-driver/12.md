# General Concept 

## Capturing video or picture usually consists of 
1. external devices e.g. camera sensors 
2. internal SOC blocks e.g. ISP's or video DMA engines or video processors 

All of these need to be represented correctly in the Devicetree for the 
devices to work.

### For External devices (camera sensors) 

SoC internal Blocks are represented as devicetree nodes and the external
devices connected to them are represented as their `child` nodes of their 
respective bus controller nodes. e.g. For MIPI CSI camera-sensors I2C, For USB 
camera-sensors USB.

Data interfaces on camera-sensors are represented as `port` child nodes.
And the devices that this data interface gets connected to needs to be 
represented as `endpoint` child nodes of the port node.

Since these devices are the part of internal SoC Blocks they have their own 
devicetree nodes. Which will contain an 'port' node and an 'endpoint' node.

We need to link the 2 endpoint nodes to each other using 'remote-endpoint' phandles for them to work.

For Example:
```yaml
camera-device@<i2c-addr> {
        ...
        ports {
                #address-cells = <1>;
                #size-cells = <0>;

                port@0 {
                        ...
                        endpoint@0 { ... };
                        endpoint@1 { ... };
                };
                port@1 { ... };
        };
};
```

### Key Rules to keep in mind while writing devicetrees for camera-devices

1. If the camera-device connects to more than one internal SoC blocks on the
**same bus** then separate `endpoint` nodes need to be provided for each 
internal SoC block. 

2. All 'port' nodes can be grouped under optional 'ports' node, which allows to
specify #address-cells, #size-cells properties independently for the 'port'
and 'endpoint' nodes and any child device nodes a device might have.


#### Further Reference Links
1. https://github.com/torvalds/linux/blob/master/Documentation/devicetree/bindings/media/video-interfaces.txt

#### Example devicetree

```yaml
i2c0: i2c@fff20000 {
        ...
        imx074: camera@1a {
                
                /* Compatible property shows compatibility */
                compatible = "sony,imx074";
                
                /* I2C device address */
                reg = <0x1a>;
                
                /* Power supply devicetree nodes  */
                vddio-supply = <&regulator1>;
                vddcore-supply = <&regulator2>;

                /* Shared clock with ov772x_1 */
                clock-frequency = <30000000>;   
                
                /* */
                clocks = <&mclk 0>;
                clock-names = "sysclk";

                /* MIPI CSI Port connections */
                port {
                        /* Data Endpoint */
                        imx074_1: endpoint {
                                clock-lanes = <0>;
                                /* MIPI CSI data lanes */
                                data-lanes = <1 2>;
                                /* Remote endpoints */
                                remote-endpoint = <&csi2_1>;
                        };
                };
        };
};

/* MIPI CSI controller node*/
csi2: csi2@ffc90000 {
        compatible = "renesas,sh-mobile-csi2";
        reg = <0xffc90000 0x1000>;
        interrupts = <0x17a0>;
        #address-cells = <1>;
        #size-cells = <0>;

        port@1 {
                /* One of CSI2I and CSI2C. */
                compatible = "renesas,csi2c";   
                reg = <1>;                      
                csi2_1: endpoint {
                        clock-lanes = <0>;
                        data-lanes = <2 1>;
                        remote-endpoint = <&imx074_1>;
                };
        };
};
```
