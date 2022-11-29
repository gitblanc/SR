module cubierta(h, dg, dp, fn){
    difference(){
        cylinder (h = h, d=dg, $fn=fn);
        
        for (i =[-40: 26.5 :44 ]) {
            translate([i, 0, 0])
                cylinder (h = h, d=dp, $fn=fn);
            translate([0, i, 0])
                cylinder (h = h, d=dp, $fn=fn);
        }
    }
}

cubierta(2, 96, 4, 30);