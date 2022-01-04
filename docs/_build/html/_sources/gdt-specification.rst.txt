*****************
GDT Specification
*****************

- Axis
  - Overview
    - Axis is the most fundemental unit of data in gdt
    - Group of `n` axis forms a "point" in an n-dimensional dataset

  - Types
    - Type of an axis is defined in the header
    - The type of the element determines the number of bytes each element will occupy
    - Each type has a unique "type code", of 8 bits, typically represented by 2 hexadecimal charecters


- Header
  - First three bytes is "gdt" encoded in utf-8
  - Following bytes represents a string of charecters encoded in utf-8 and terminating with U+0000 (0x00). This string is called the Title
  - Following 8 bytes mentions `n`, the dimension of the dataset
  - Following `n` bytes metions the type code of each dimensions
  - Following 16 bytes mentions `m`, the number of points the in the dataset

- Body
  - Label
    - Following bytes is a series of `n` strings representing the label for each dimensional axis
    - The strings are encoded in utf-8 and each strings terminates with U+0000 (0x00)
    - Each of these strings is called "Label", also called "Axis Label"
    - They act as identifiers of each axis
  - Data
    - The data contains `m` points in series
    - Each point has `n` axis
    - Therfore, the total elements inside the data is `nm`
