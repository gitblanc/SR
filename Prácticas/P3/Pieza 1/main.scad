use <rueda.scad>
use <cuerpo.scad>
use <Base.scad>
use <placa.scad>

radioRueda = 20;
anchoRueda = 10;
radioInterno = 17;
anchoInterno = 3;
radioPalier = 5;
anchoPalier = 10;
radioagujero = 2.5;
anchoagujero = 10;
offsetAgujero = 20;


altoC = 40;
anchoC = 20;
largo = 40;
anchoagujero = 40;
radioagujero = 3;
offsetAgujero = 20;
offsetTriangulos = 3;
radioTriangulos = 1;

palieres = 110;

rotate([90,0,90])
translate([-20,20,-50])
    rueda(radioRueda,anchoRueda,radioInterno,anchoInterno,radioPalier,anchoPalier, radioagujero, anchoagujero, offsetAgujero);

rotate([90,0,90])
translate([-20,20,50])
    rueda(radioRueda,anchoRueda,radioInterno,anchoInterno,radioPalier,anchoPalier, radioagujero, anchoagujero, offsetAgujero);
    
    rotate([90,0,90])
translate([-80,20,-50])
    rueda(radioRueda,anchoRueda,radioInterno,anchoInterno,radioPalier,anchoPalier, radioagujero, anchoagujero, offsetAgujero);

rotate([90,0,90])
translate([-80,20,50])
    rueda(radioRueda,anchoRueda,radioInterno,anchoInterno,radioPalier,anchoPalier, radioagujero, anchoagujero, offsetAgujero);
    
rotate([90,0,90])
    translate([-40,10,-40])
        cuerpo(altoC,anchoC,largo, anchoagujero,radioagujero, offsetAgujero, offsetTriangulos, radioTriangulos);
        
rotate([90,0,-90])
    translate([0,10,-40])
        cuerpo(altoC,anchoC,largo, anchoagujero,radioagujero, offsetAgujero, offsetTriangulos, radioTriangulos);

rotate([-180,0,0])
    translate([-40,60,-30])
        base();

rotate([0,180,0])
    translate([-40,-100,-30])
        base();

rotate([0,0,90])  
    translate([-100,-40,30])  
        placa();

rotate([90,0,90])  
    translate([-20,20,-55])
        cylinder(h = palieres, r = radioagujero, $fn=offsetAgujero);
        
rotate([90,0,90])  
    translate([-80,20,-55])
        cylinder(h = palieres, r = radioagujero, $fn=offsetAgujero);