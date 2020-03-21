#include "map.h"
void Map::init(int map_w, int map_h, int map_res)
{
  /*map_w: map width in m
    map_h: map heigh in m
    map_res: map res in m/cell 
  */
  map.info.width = map_w / map_res + 1;
  map.info.height = map_h / map_res + 1;
  map.info.resolution = map_res;

  //origin stores positon and pose of origin(cell (0, 0)) in real-world
  map.info.origin.position.x = map_w / 2;
  map.info.origin.position.y = map_w / 2;
  map.info.origin.position.z = 0;

  map.info.origin.orientation.x = 0; //orientation is stores as quaternion: learn!!
  map.info.origin.orientation.y = 0;
  map.info.origin.orientation.z = 0;
  map.info.origin.orientation.w = 1;

  map.data.resize(map.info.height * map.info.width); //resize() in c++?
  map.data.assign(map.info.height * map.info.width, -1);
}

void Map::clearMap()
{
  map.data.assign(map.info.width * map.info.height, 0);
}

void Map::publish(const ros::Publisher &pub)
{
  pub.publish(map);
}
