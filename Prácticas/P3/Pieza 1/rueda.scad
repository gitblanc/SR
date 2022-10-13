module rueda(radioRueda,ancho,radioInterno, anchoInterno, radioPalier, anchoPalier){ 
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
        }
        //Palier
            cylinder(h= anchoPalier, r = radioPalier, center = true, $fn=20);
}
}

rueda(20,10,17,3,5,10);