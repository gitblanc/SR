
module Box(boxGapWidth, boxWidth, boxLarge, boxHeight, centerGapPosition){
    difference(){
        //Main Box
        box=[boxWidth,boxLarge,boxHeight];cube(box,false);
        //Box Holes
        for(i = [7:12:boxWidth]){
            for(j = [7:14:boxLarge]){
                translate([i,j,-1])
                    cylinder(r=2, h=20, $fn=20);
            }
        }
        //Center Cube
        translate([-1,centerGapPosition,-1])
            cube([boxGapWidth,40,10]);

        //Front Gap
        translate([-1,0.5,3.5])
            cube([boxGapWidth,1.5,3]);
        translate([-1,-1,4.3])
            cube([boxGapWidth,2,1.5]);

        //Back Gap
        translate([-1,29,3.5])
            cube([boxGapWidth,1.5,3]);
        translate([-1,30,4.3])
            cube([boxGapWidth,2,1.5]);
        
        //Gap top
        translate([15,centerGapPosition,-1])
            cube([20,40,11]);
    }
    difference(){
        //Trapecio Ruedas Traseras
        translate([50,57,7])
            rotate([0,-90,0])
                cylinder(r=10, h=50, $fn=5);
        
        translate([15,centerGapPosition,-2])
            cube([20,40,20]);
        
        translate([2,centerGapPosition,-2])
            cube([46,40,20]);
        
        translate([-1,centerGapPosition,10])
            cube([52,40,20]);
    }
}