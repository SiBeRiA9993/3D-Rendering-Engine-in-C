# 3D-Rendering-Engine-in-C
WindowsApi<br/>
written in C<br/>
I have not cleaned up the code yet!
# Contorl
Up       : space <br/>
Down     : shift <br/>
Move     : w,a,s,d <br/>
Rotation : ↑,↓,←,→ <br/>
# ScreenShots
![screenshot_1](https://github.com/SiBeRiA9993/3D-Rendering-Engine-in-C/blob/master/ScreenShot/SS1.png)
![screenshot_2](https://github.com/SiBeRiA9993/3D-Rendering-Engine-in-C/blob/master/ScreenShot/SS2.png)
![screenshot_3](https://github.com/SiBeRiA9993/3D-Rendering-Engine-in-C/blob/master/ScreenShot/SS3.png)
# Main&Important Code
### Rotation matrix
![code_1](https://github.com/SiBeRiA9993/3D-Rendering-Engine-in-C/blob/master/ScreenShot/IC1.png)
Horizontal_rotation * Vertical_rotation <br/>
### Get Coordinate to output
![code_2](https://github.com/SiBeRiA9993/3D-Rendering-Engine-in-C/blob/master/ScreenShot/IC2.png)
### Moving Coordinate Calculation
![code_3](https://github.com/SiBeRiA9993/3D-Rendering-Engine-in-C/blob/master/ScreenShot/IC3.png)
Let "Horizontal rotation" be "H"and "Distance traveled" be "D"<br/>
The player's "Horizontal rotation" value is stored in degree,<br/>
and it should be calculated in radian.<br/>
Therefore, H = (Horizontal rotation) * (PI / 180).
### When moving forward <br/>
player_x += cos(H+(π/2))*(-D) <br/>
player_z += sin(H+(π/2))*D <br/>
### When moving backward <br/>
player_x += cos(H-(π/2))*(-D) <br/>
player_z += sin(H-(π/2))*D <br/>
### When moving left <br/>
player_x += cos(H+π)*D <br/>
player_z += sin(H+π)*(-D) <br/>
### When moving right <br/>
player_x += cos(H)*D <br/>
player_z += sin(H)*(-D) <br/>
