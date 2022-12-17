// Eduardo Blanco Bielsa - UO285176
module rueda(radioRueda,ancho,radioInterno, anchoInterno, radioPalier, anchoPalier, radioagujero, anchoagujero, offsetAgujero){ 
    difference(){
        union(){
            difference(){
                // rueda
                cylinder(h= ancho, r = radioRueda, center = true);
                translate([0, 0, 4])
                // rueda interna
                cylinder(h= anchoInterno, r = radioInterno, center = true);
                translate([0, 0, -4])
                // rueda interna
                cylinder(h= anchoInterno, r = radioInterno, center = true);
                
                //Agujeros de la rueda
                translate([-7,-7,-5])
                    cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
                translate([7,-7,-5])
                    cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
                translate([-10,0,-5])
                    cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
                translate([-7, 7, -5])
                    cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
                translate([10,0, -5])
                    cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
                translate([7, 7, -5])
                    cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
                translate([0, 10, -5])
                    cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
                translate([0, -10, -5])
                    cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);           
            }
            //Palier
                cylinder(h= anchoPalier, r = radioPalier, center = true, $fn=offsetAgujero);
    }
            intersection() {
                //Agujero central
                translate([0, 0, -5])
                    cylinder(h = anchoagujero*2, r = radioagujero, $fn=offsetAgujero);  
                        translate([3,0,0])
                            cube(10, center = true);
}
            
}
}

rueda(20,10,17,3,5,10, 2.5, 10, 20);