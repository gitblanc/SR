// Pieza 3 code
// GRUPO B3
// Mateo Rico Iglesias - UO277172

use <Wheels.scad>
use <Box.scad>
//Variables for Wheels
wheelRadius = 10;
wHolesRadius = 5;
wHolesCount = 8;
lGapRadius = 1.5;
iGapRadius = 8.5;
circleSmooth = 40;

//Variables for Box Body
boxGapWidth = 54;
boxWidth = 50;
boxLarge = 70;
boxHeight = 11;
centerGapPosition = 31;

//Left Wheels
Wheels(wheelRadius, wHolesRadius, wHolesCount, lGapRadius, iGapRadius, circleSmooth);

//Right Wheels
rotate([0, 180, 0])
translate([-50, 0, -10])
Wheels(wheelRadius, wHolesRadius, wHolesCount, lGapRadius, iGapRadius, circleSmooth);

//Body
Box(boxGapWidth, boxWidth, boxLarge, boxHeight, centerGapPosition);