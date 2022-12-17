// Eduardo Blanco Bielsa - UO285176
module cuerpo(alto,ancho,largo, anchoagujero, radioagujero, offsetAgujero, offsetTriangulos, radioTriangulos){
    difference(){
        cube([alto,ancho,largo]);
        
        //Agujeros
        rotate([90, 0, 0])
            translate([30,10,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
        rotate([90, 0, 0])
            translate([10,10,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
        rotate([90, 0, 0])
            translate([30,30,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
        rotate([90, 0, 0])
            translate([10,30,-20])
                        cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
        //Agujero de debajo
        translate([20,10,0])
                        cylinder(h = anchoagujero, r = 1, $fn=offsetAgujero);
        //Cubo agujero
        translate([14,4,5]){
            cube([alto/2 -8,ancho-7,largo]);
        }
        //Pequeño reborde interior cilindrico
        translate([20,10,4])
               cylinder(h = anchoagujero, r = radioagujero, $fn=offsetAgujero);
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
                cylinder (h = largo, r= radioTriangulos, $fn=offsetTriangulos);
        rotate([0,0,90])
            translate([7.4,-0.8,0])
                cylinder (h = largo, r= radioTriangulos, $fn=offsetTriangulos);
        rotate([0,0,-90])
            translate([-12.6,39.2,0])
                cylinder (h = largo, r= radioTriangulos, $fn=offsetTriangulos);
        rotate([0,0,-90])
            translate([-12.6,0.8,0])
                cylinder (h = largo, r= radioTriangulos, $fn=offsetTriangulos);
        
}

cuerpo(40,20,40, 40,2, 20, 3, 1);