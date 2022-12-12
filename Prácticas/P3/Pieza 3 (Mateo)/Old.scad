wheelRadius = 10;
wHolesRadius = 5;
wHolesCount = 8;
lGapRadius = 1.5;
iGapRadius = 8.5;

difference(){
    //Main Box
    box=[50,70,10];cube(box,false);
    //Box Holes
    for(i = [7:12:50]){
        for(j = [7:14:70]){
            translate([i,j,-1])
                cylinder(r=2, h=20, $fn=20);
        }
    }
    //Center Cube
    translate([-1,31,1])
        cube([54,8,8]);

    //Front Gap
    translate([-1,1,3.5])
        cube([54,1.5,3]);
    translate([-1,-1,4.3])
        cube([54,2,1.5]);

    //Back Gap
    translate([-1,68,3.5])
        cube([54,1.5,3]);
    translate([-1,69,4.3])
        cube([54,2,1.5]);
}
//Left Wheels
for(w = [57.5,57,13]){
    rotate([0,90,0])
    translate ([-5,w,-5]){
        difference (){
            cylinder (h=5, r=wheelRadius, $fn=40); //Wheel
           
            translate([0, 0, -1]) {
                cylinder (h=0, r=0);
                make_ring_of (radius = wHolesRadius, count = wHolesCount)
                    cylinder (r = lGapRadius, h = 10, $fn=20); //Wheel Little Gaps
                cylinder(h = 5, r = iGapRadius, $fn=20);//Inside Gap
            }
            
        }
    
    }
    //Wheel Bar
    rotate([0,90,0])
    translate([-5, w, -4])
    cylinder(h = 2, r=2);
}

//Right Wheels
for(w = [-57.5,-13]){
    rotate([0,90,180])
    translate ([-5,w,-55]){
        difference (){
            cylinder (h=5, r=wheelRadius, $fn=40); //Wheel
            translate([0, 0, -1]) {
                cylinder (h=0, r=0);
                make_ring_of (radius = wHolesRadius, count = wHolesCount)
                    cylinder (r = lGapRadius, h = 10, $fn=20);//Wheel Little Gaps
                cylinder(h = 5, r = iGapRadius, $fn=20);//Inside Gap
            }
            
        }
    
    }
    //Wheel Bar
    rotate([0,90,180])
    translate([-5, w, -54])
    cylinder(h = 2, r=2, $fn=20);
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
 

