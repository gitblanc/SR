module base(){
    union(){
            difference(){
                cube([20,40,3]);
                translate([10,10,0])
                    cylinder(h= 3, d = 5, $fn=20);
                translate([10,30,0])
                    cylinder(h= 3, d = 5, $fn=20);
            } 
           difference(){ 
                rotate([90,0,90])
                    translate([20,0,0])
                        cylinder(h = 3, r=22, $fn=6);
                
               translate([-30,-5,-50])
                    cube (50);
               translate([0,-5,0])
                    cube (5);
               translate([0,40,0])
                    cube (5);
               rotate([90,0,90])
                    translate([20,10,0])
                        cylinder(h= 3, d = 5, $fn=20);
           }
    }
}
