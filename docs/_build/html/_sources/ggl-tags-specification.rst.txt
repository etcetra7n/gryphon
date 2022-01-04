***********************
GGL Tags Specification
***********************

<!Comments>
===========

- this is the comment tag and can be used anywhere
- Everthing inside the tag is ignored

<ggl><\/ggl>
============

- Everthing is enclosed in this tag

<head><\/head>
==============

<out/>
======

    <out resolution = {*length* **x**, *length* **y**}>

- **x** is the horizontal resolution
- **y** is the vertical resolution

<data/>
=======

    <data type=(*byte* **T[n]**)>

- T[n] is a list of type code that that defines the types of data the template accepts
- for example, `<data type={0x00, 0x00}>` means the first and second axis is of float type
  
<body><\/body>
==============

- Define the layout of the template here

<plot><\/plot>
==============

- used to define axis data and label etc.

<axis><axis>
============

    <axis dim=(*int* **n**) label=(*string* **l**)> (**Data[m]**) <\/axis>

- **n** is the dimension of the axis
- **l** is the label of the axis
- **Data[m]** is list of data in the nth dimension. It is of the datatype defined in <data /> tag in the header
