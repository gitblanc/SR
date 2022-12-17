// Eduardo Blanco Bielsa - UO285176
module tubo(h, d, fn, hull1, hull2, hull3){
    difference(){
        hull(){
            translate([0,90,5])
            rotate([90,-45,0])
            cylinder (h = h, d=d, $fn=fn);
          
        
            translate([0,-93,2])
            rotate([0,0,30])
            cylinder (h = hull1, d=hull2, $fn=hull3);
        }
      
        translate([0,90,5])
        rotate([90,-45,0])
        cylinder (h = h, d=d-4, $fn=fn);
    }
}

module helice(h, d, fn, hc, dc, fnc, hcc, dcc, fncc, hh, dh, hull1, hull2, hull3){
    difference(){
        union(){
            translate([0,-78,0])
            rotate([0,0,90])
            cylinder (h = hc, d=dc, $fn=fnc);
            tubo(h, d, fn, hull1, hull2, hull3);
        }
        translate([0,82,0])
        cylinder (h = hcc, d=dcc, $fn=fncc);
        translate([0,56,0])
        cylinder (h = hcc, d=dcc, $fn=fncc);
        
        translate([0,-88,0])//hélice
        cylinder (h = hcc, d=dcc, $fn=fncc);
        translate([0,-68,0])
        cylinder (h = hcc, d=dcc, $fn=fncc);
        translate([10,-78,0])
        cylinder (h = hcc, d=dcc, $fn=fncc);
        translate([-10,-78,0])
        cylinder (h = hcc, d=dcc, $fn=fncc);
        
        translate([0,-78,0])
        cylinder (h = hcc*2, d=dcc+5.8, $fn=fncc);
}
hull(){
    translate([0,-55,9])
    cylinder (h = hh, d=dh, $fn=fncc);
    translate([0,-55,11])
    cylinder (h = hh+29, d=1, $fn=fncc);
}
}

helice(180,14,4, 2,32,6, 10,3,30, 1, 9.8, 8, 2, 3);