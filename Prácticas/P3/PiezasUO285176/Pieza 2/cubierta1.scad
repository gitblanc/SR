// Eduardo Blanco Bielsa - UO285176
module cubierta1(h, dg, dp, fn){
    difference(){
        cylinder (h = h, d=dg, $fn=fn);
        
        for (i =[-41: 27 :41 ]) {
            translate([i, 0, 0])
                cylinder (h = h, d=dp, $fn=fn);
            translate([0, i, 0])
                cylinder (h = h, d=dp, $fn=fn);
        }
    }
}

cubierta1(2, 96, 4, 30);