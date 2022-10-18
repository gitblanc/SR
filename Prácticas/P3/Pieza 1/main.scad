use <rueda.scad>
use <cuerpo.scad>
use <Base.scad>
use <placa.scad>

rotate([90,0,90])
translate([-20,20,-50])
    rueda(20,10,17,3,5,10, 2.5, 10);

rotate([90,0,90])
translate([-20,20,50])
    rueda(20,10,17,3,5,10, 2.5, 10);
    
    rotate([90,0,90])
translate([-80,20,-50])
    rueda(20,10,17,3,5,10, 2.5, 10);

rotate([90,0,90])
translate([-80,20,50])
    rueda(20,10,17,3,5,10, 2.5, 10);
    
rotate([90,0,90])
    translate([-40,10,-40])
        cuerpo(40,20,40, 40,2);
        
rotate([90,0,-90])
    translate([0,10,-40])
        cuerpo(40,20,40, 40,2);

rotate([-180,0,0])
    translate([-40,60,-30])
        base();

rotate([0,180,0])
    translate([-40,-100,-30])
        base();

rotate([0,0,90])  
    translate([-100,-40,30])  
        placa();

rotate([90,0,90])  
    translate([-20,20,-55])
        cylinder(h = 110, r = 2, $fn=20);
        
rotate([90,0,90])  
    translate([-80,20,-55])
        cylinder(h = 110, r = 2, $fn=20);