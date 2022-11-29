module tubo(){
    difference(){
        translate([0,90,5])
        rotate([90,-45,0])
            cylinder (h = 180, d=14, $fn=4);
        
        translate([0,90,5])
        rotate([90,-45,0])
            cylinder (h = 180, d=10, $fn=4);
    }
}

module helice(){
    difference(){
        union(){
            translate([0,-78,0])
            rotate([0,0,90])
            cylinder (h = 2, d=32, $fn=6);
            tubo();
        }
        translate([0,82,0])
        cylinder (h = 10, d=3, $fn=30);
        translate([0,56,0])
        cylinder (h = 10, d=3, $fn=30);
        
        translate([0,-88,0])//hélice
        cylinder (h = 10, d=3, $fn=30);
        translate([0,-68,0])
        cylinder (h = 10, d=3, $fn=30);
        translate([10,-78,0])
        cylinder (h = 10, d=3, $fn=30);
        translate([-10,-78,0])
        cylinder (h = 10, d=3, $fn=30);
}
}

helice();