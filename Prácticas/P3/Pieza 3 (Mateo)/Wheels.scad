module Wheels(wheelRadius, wHolesRadius, wHolesCount, lGapRadius, iGapRadius, circleSmooth){
    //Wheels
    for(w = [57.5,57,13]){
        rotate([0,90,0])
        translate ([-5,w,-5]){
            difference (){
                cylinder (h=5, r=wheelRadius, $fn=circleSmooth); //Wheel
               
                translate([0, 0, -1]) {
                    cylinder (h=0, r=0);
                    make_ring_of (radius = wHolesRadius, count = wHolesCount)
                        cylinder (r = lGapRadius, h = 10, $fn=circleSmooth); //Wheel Little Gaps
                    cylinder(h = 5, r = iGapRadius, $fn=circleSmooth);//Inside Gap
                }
                
            }
        
        }
        //Wheel Bar
        rotate([0,90,0])
        translate([-5, w, -4])
        cylinder(h = 2, r=2, $fn=circleSmooth);
    }
}


module make_ring_of (radius, count)
{
    for (a = [0: count -1]){
        angle = a * 360 /count;
       
        translate (radius * [sin(angle), -cos(angle), 0])
            rotate ([0, 0, angle])
                children ();
    }
}