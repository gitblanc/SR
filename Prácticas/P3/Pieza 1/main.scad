use <rueda.scad>
use <cuerpo.scad>
use <base.scad>

rotate([90,0,90])
translate([-20,20,-50])
    rueda(20,10,17,3,5,10, 2.5, 10);

rotate([90,0,90])
translate([-20,20,40])
    rueda(20,10,17,3,5,10, 2.5, 10);
    
    rotate([90,0,90])
translate([-80,20,-50])
    rueda(20,10,17,3,5,10, 2.5, 10);

rotate([90,0,90])
translate([-80,20,40])
    rueda(20,10,17,3,5,10, 2.5, 10);
    
rotate([90,0,90])
    translate([-50,10,-40])
        cuerpo(40,20,70, 40,2);

base();