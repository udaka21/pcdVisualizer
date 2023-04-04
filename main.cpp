#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <thread>
#include <chrono>

int main()
{
    pcl::visualization::PCLVisualizer viewer("Cloud Viewer");
    viewer.setBackgroundColor(0, 0, 0);

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    if (pcl::io::loadPCDFile<pcl::PointXYZRGB>("Captured_Frame.pcd", *cloud) == -1)
    {
        PCL_ERROR("Couldn't read file Captured_Frame.pcd\n");
        return (-1);
    }

    viewer.addPointCloud(cloud, "captured frame");

    std::cout << "Loaded " << cloud->size() << " data points from Captured_Frame.pcd" << std::endl;

    while (!viewer.wasStopped())
    {
        viewer.spinOnce(100);
        std::this_thread::sleep_for(std::chrono::microseconds(100000));
    }

    return (0);
}
