module placa(hc1, dc1, fnc1, des1, fnes, hc2, des2){
    difference(){
        esferaHueca(des1, fnes, hc2, des2);
        translate([0,41,-2])
        cylinder (h = hc1, d=dc1, $fn=fnc1);
        translate([41,0,-2])
        cylinder (h = hc1, d=dc1, $fn=fnc1);
        translate([0,-41,-2])
        cylinder (h = hc1, d=dc1, $fn=fnc1);
        translate([-41,0,-2])
        cylinder (h = hc1, d=dc1, $fn=fnc1);
    }
} 

module esferaHueca(des1, fnes, hc2, des2){
    difference(){
        difference(){
           esfera(hc2, des2, fnes);
           translate([0,0,-20])
           sphere(d = des1, $fn = fnes); 
        }
    translate([0,0,-80])
    cylinder (h = 80, d=94, $fn=fnes);  
}
}

module esfera(hc2, des2, fnes){
    union(){
       difference(){
          cylinder (h = hc2, d=94, $fn=fnes);
          cylinder (h = hc2, d=64, $fn=fnes);
       }
       translate([0,0,-20])
       sphere(d = des2, $fn = fnes);
    }
}

placa(4, 4, 30, 85, 40, 2, 86);