### introduction

Some algorithms about computional geometry.

### package type

Dependent packages will be compiled in its folder and independent package will be compiled in root folder.

### assets

Local resources are stored in folder `assets_local`, where resources are used only this repositories. Global resources are stored in folder `assets`, where resources also are used in other repositories. This folder is a git submodule, which means it's a seperate git repository and therefore, it won't enlarge git of current repository.

### dependency

* cmake
* json-cpp
* pcl

### build and install

```bash
./cbuild.sh
```

### delaunay

This is a dependent package about delaunay and volonoi. It provides a GUI to display delaunay triangulation and volonoi using qt. You can run it as `README.md` in this package.

```bash
cd delaunay
mkdir -p build
cd build
cmake ..
make
./delaunay
```

### arc

These aren't a dependent package. Some algorithms about arc.

##### midpoint_angle

Calculate midpoint of two points on a circle.

##### min_arc

It can calculate a minimal arc that cover three points on a circle.

### polyline_simplification

A algorithm to reduce vertice of polyline.
`generate_polyline.py` in folder `assets` is used to generate polyline and `draw_polyline.py` is used to draw polyline.

```bash
# generate polyline
cd assets
python3 generate_polyline.py

# draw simplified polyline
cd ../polyline_simplification
python3 draw_polyline
```

##### radial_distance

Keep only one point in an circular area.

##### perpendicular_distance

##### douglas_peucker

### line

Algorithms about line.

##### perpendicular_bisector

Method to calculate perpendicular bisector of line segment.