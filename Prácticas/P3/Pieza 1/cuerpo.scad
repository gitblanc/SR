module cuerpo(alto,ancho,largo, anchoagujero, radioagujero){
    difference(){
        cube([alto,ancho,largo]);
        
        //Agujeros
        rotate([90, 0, 0])
            translate([30,10,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=20);
        rotate([90, 0, 0])
            translate([10,10,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=20);
        rotate([90, 0, 0])
            translate([30,30,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=20);
        rotate([90, 0, 0])
            translate([10,30,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=20);
        //Agujero de debajo
        translate([20,10,0])
                        cylinder(h = anchoagujero, r = 1, $fn=20);
        //Cubo agujero
        translate([14,4,5]){
            cube([alto/2 -8,ancho-7,largo]);
        }
        //Pequeño reborde interior cilindrico
        translate([20,10,4])
               cylinder(h = anchoagujero, r = radioagujero, $fn=20);
        //Bifurcaciones rectangulares de los laterales
        translate([0,7,0]){
            cube([5,6,largo]);
        }
        translate([35,7,0]){
            cube([5,6,largo]);
        }
    }
    //Bifurcaciones triangulares exteriores
        rotate([0,0,90])
            translate([7.4,-39.2,0])
                cylinder (h = largo, r= 1, $fn=3);
        rotate([0,0,90])
            translate([7.4,-0.8,0])
                cylinder (h = largo, r= 1, $fn=3);
        rotate([0,0,-90])
            translate([-12.6,39.2,0])
                cylinder (h = largo, r= 1, $fn=3);
        rotate([0,0,-90])
            translate([-12.6,0.8,0])
                cylinder (h = largo, r= 1, $fn=3);
        
}

cuerpo(40,20,40, 40,2);