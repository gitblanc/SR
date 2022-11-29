use <cover.scad>
use <spacers.scad>
use <cubierta1.scad>
use <cubierta2.scad>
use <helice.scad>

p1 = 4;
p2 = 30;
p3 = 85;
p4 = 40;
p5=p1/2;
p6=p3+1;

c1 = 2;
c2 = 94;
c3 = c1*2;
c4 = 30;

s1 = 22;
s2 = 4;
s3 = 20;

//180,14,4, 2,32,6, 10,3,30, 1, 9.8, 8, 2, 3)

h1 = 180;
h2 = 14;
h3 = 4;
h4 = 2;
h5 = 32;
h6 = 6;
h7 = 10;
h8 = 3;
h9 = 30;
h10 = 1;
h11 = 9.8;
h12 = 8;
h13 = 2;
h14 = 3;

placa(p1, p1, p2, p3, p4, p5, p6);
translate([0,0,-10])
cubierta1(c1, c2, c3, c4);
translate([0,0,-20])
cubierta2(c1, c2, c3, c4);

//spacers
translate([-41,0,-20])
spacer(s1, s2, s3);
translate([41,0,-20])
spacer(s1, s2, s3);
translate([0,-40,-20])
spacer(s1, s2, s3);
translate([0,40,-20])
spacer(s1, s2, s3);
//helices
translate([0,-97,-10])
helice(h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12,h13,h14);
rotate([0,0,180])
translate([0,-96,-10])
helice(h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12,h13,h14);
rotate([0,0,90])
translate([0,-96,-10])
helice(h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12,h13,h14);
rotate([0,0,-90])
translate([0,-96,-10])
helice(h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12,h13,h14);