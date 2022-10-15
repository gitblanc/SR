module cuerpo(alto,ancho,largo, anchoagujero, radioagujero){
    difference(){
        cube([alto,ancho,largo]);
        
        //Agujeros
        rotate([90, 0, 0])
            translate([30,12,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=20);
        rotate([90, 0, 0])
            translate([10,12,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=20);
        rotate([90, 0, 0])
            translate([30,32,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=20);
        rotate([90, 0, 0])
            translate([10,32,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=20);
        //Agujero de debajo
        translate([20,0,0])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=20);
    }
}

cuerpo(40,20,40, 40,2);