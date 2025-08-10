## OS tree 

git config --global user.email "yogesh.hegde@external.atlascopco.com"
git config --global user.name "Yogesh Hegde"
repo init -u https://github.com/advancedtelematic/updater-repo.git -m dunfell.xml
repo sync -j16

Change the local.conf file 
```sh
GARAGE_SIGN_AUTOVERSION = "1"
OSTREE_SYSROOT_READONLY = "1"
# Update the ostree summary
OSTREE_UPDATE_SUMMARY = "1"
```

Change the uEnv.txt in meta-updater-raspberrypi/recipes-bsp/u-boot-otascript/u-boot-otascript/uEnv.txt 
```sh
bootcmd_run=bootm ${ramdisk_addr_r} ${fit_conf}
```
Run command 

bitbake -k core-image-minimal

IMAGE_INSTALL:append() = " nano"

bitbake -k core-image-minimal

