module base(anchoc,largoc, altoc, alturaAgujero,diamAgujero, offset){
    union(){
            difference(){
                cube([anchoc,largoc,altoc]);
                translate([10,10,0])
                    cylinder(h= alturaAgujero, d = diamAgujero, $fn=offset);
                translate([10,30,0])
                    cylinder(h= alturaAgujero, d = diamAgujero, $fn=offset);
            } 
           difference(){ 
                rotate([90,0,90])
                    translate([20,0,0])
                        cylinder(h = alturaAgujero, r=22, $fn=6);
                
               translate([-30,-5,-50])
                    cube (50);
               translate([0,-5,0])
                    cube (5);
               translate([0,40,0])
                    cube (5);
               rotate([90,0,90])
                    translate([20,10,0])
                        cylinder(h= alturaAgujero, d = diamAgujero, $fn=offset);
           }
    }
}
base(20,40,3,3,5,20);