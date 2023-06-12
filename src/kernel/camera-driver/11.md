# Structure of the camera device driver 
The camera device driver is very similar to a char device driver 

The key components that make up the camera device driver are 
1. Driver structure 
2. Device structure
3. Initialization and Exit Functions
4. Device operations structure
5. Device operations functions 

### Driver structure 
Driver structure stores info, data and functions related to the the driver.  
Every driver has this structure.

For example:
```c
static struct i2c_driver ov5640_i2c_driver = {
	.driver = {
		.name  = "ov5640",
		.of_match_table	= ov5640_dt_ids,
	},
	.id_table = ov5640_id,
	.probe    = ov5640_probe,
	.remove   = ov5640_remove,
};
```
Explanation :
1. The structure is of type `struct i2c_driver`
2. `.name` - Denotes the name of the i2c device.
3. `.of_match_table` - Link to the Device Tree compatible property.(Used to match with the compatible property in the Device Tree)
4. `.id_table` - Link to the ID table property (used to Initialize the device driver before Device Trees)
5. `.probe` - Function which executes when the kernel module initializes.
6. `.remove` - Function which executes when the kernel module exits.

### Device structure 
Device structure stores all the info, data and functions which help manage the camera sensor device.

```c
struct ov5640_dev {
	struct i2c_client *i2c_client;
	struct v4l2_subdev sd;
	struct media_pad pad;
	struct v4l2_fwnode_endpoint ep; /* the parsed DT endpoint info */
	struct clk *xclk; /* system clock to OV5640 */
	u32 xclk_freq;

	struct regulator_bulk_data supplies[OV5640_NUM_SUPPLIES];
	struct gpio_desc *reset_gpio;
	struct gpio_desc *pwdn_gpio;
	bool   upside_down;

	/* lock to protect all members below */
	struct mutex lock;

	int power_count;

	struct v4l2_mbus_framefmt fmt;
	bool pending_fmt_change;

	const struct ov5640_mode_info *current_mode;
	const struct ov5640_mode_info *last_mode;
	enum ov5640_frame_rate current_fr;
	struct v4l2_fract frame_interval;

	struct ov5640_ctrls ctrls;

	u32 prev_sysclk, prev_hts;
	u32 ae_low, ae_high, ae_target;

	bool pending_mode_change;
	bool streaming;
};
```
The key data structures are:
1. `struct i2c_client *i2c_client` - Used to store driver data related to the I2C device. (Since camera is an I2C device driver it is used to store all data related to I2C device driver) 
2. `struct v4l2_subdev sd` - Used to store driver data related to the V4L2 device. (This driver is also an instance of V4L2 sub device)
3. `struct media_pad pad` - Used to store driver data related to the Media subsystem. (This driver is also an instance of a media device)

### Initialization and Exit Functions
The probe and remove functions are the Initialization and Exit Functions.

#### Role of Initialization function
The role is to 
1. Initialize the data structures
1. Initialize device operations
1. Register the device driver module with the kernel.

#### Role of Exit function
The role is to 
1. Terminate the data structures
1. Terminate all device operations 
1. Un-register the device driver module with the kernel.

### Device operations structure
Device operation structure contains function pointers to store all possible operations(functions) that can be done on the device.
```c
static const struct v4l2_subdev_ops imx274_subdev_ops = {
	.pad = &imx274_pad_ops,
	.video = &imx274_video_ops,
};
```

### Device operation functions 
All the `functions` inside the camera driver are **device operation functions** or *helper functions* which help the device operation functions.

All these functions are responsible for performing specific operations on the demand of the user.     
