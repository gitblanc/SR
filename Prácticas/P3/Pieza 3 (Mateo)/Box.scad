
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
        translate([-1,centerGapPosition,1])
            cube([boxGapWidth,8,8]);

        //Front Gap
        translate([-1,0.5,3.5])
            cube([boxGapWidth,1.5,3]);
        translate([-1,-1,4.3])
            cube([boxGapWidth,2,1.5]);

        //Back Gap
        translate([-1,68,3.5])
            cube([boxGapWidth,1.5,3]);
        translate([-1,69,4.3])
            cube([boxGapWidth,2,1.5]);
    }
}