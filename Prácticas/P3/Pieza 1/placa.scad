module placa(){
    difference(){
        cube([100,80,3]);
        
        for (i =[10: 20 :100 ], j = [10: 20 :80 ]){ 
            translate([i, j, 0])
                cylinder (h = 20, d=6, $fn=20);
    }
        
    }
}