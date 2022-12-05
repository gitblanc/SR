module cubierta2(h, dg, dp, fn){
    difference(){
        cylinder (h = h, d=dg, $fn=fn);
        
        for (i =[-41: 27 :41 ]) {
            translate([i, 0, 0])
                cylinder (h = h, d=dp, $fn=fn);
            translate([0, i, 0])
                cylinder (h = h, d=dp, $fn=fn);
        }
        for (i =[-30: 60 :30 ]) {
            translate([i, 0, 0])
                cylinder (h = h, d=dp-1, $fn=fn);
            translate([0, i, 0])
                cylinder (h = h, d=dp-1, $fn=fn);
        }
        for(i =[-20: 40 :20 ]){
            translate([i, i, 0])
                cylinder (h = h, d=dp-1, $fn=fn); 
            translate([-i, i, 0])
                cylinder (h = h, d=dp-1, $fn=fn);    
        }
    }
}

cubierta2(2, 96, 4, 30);