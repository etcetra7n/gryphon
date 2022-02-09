namespace Graph
{
int
raster (struct pixel graph[V][H])
{
  float xmin = -4.0;
  float xmax = 4.0;
  float ymin = -4.0;
  float ymax = 4.0;
  float dx = (xmax - xmin) / H;
  float dy = (ymax - ymin) / V;

  for (unsigned int i = 0; i < V; i++) /*Rows loops downwards*/
    {
      float y = ymax - (dy * i);           /*current y value*/
      float ly = y - dy;                   /*last y value*/
      for (unsigned int j = 0; j < H; j++) /*Columns loops towards the right*/
        {
          float x = xmin + (dx * j); /*current x value*/
          float lx = x - dx;         /*last x value*/
          struct pixel px;           /*curent pixel*/

          if (((x)-y >= 0) && ((lx)-ly <= 0))
            /*shades the pixel which statisfies the equation*/
            px = { 204, 86, 82 };
          else if (((x >= 0) && (lx < 0)) || ((y >= 0) && (ly < 0)))
            /*shades the points where either x=0 or y=0*/
            px = { 25, 25, 25 };
          else
            /*shades the rest of the area with white*/
            px = { 255, 255, 255 };
          graph[i][j] = px;
        }
    }
  return 0;
}
} // namespace Graph
