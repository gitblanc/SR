union(){
    difference(){
        cube([20,40,3]);
        translate([10,10,0])
            cylinder(h= 3, d = 6, $fn=20);
        translate([10,30,0])
            cylinder(h= 3, d = 6, $fn=20);
    }  
    translate([0,10])
        cube([3,20,20]);
}
polyhedron(
    points=[[0,40,3],[3,40,3],[0,30,20],[3,30,20],[0,30,3]],[3,30,3],
    faces=[[0,1,2,3], [0,4,5]]
);
