/*
 * Copyright (c) 2016, Shaun Edwards, PlusOne Robotics
 * All rights reserved.
 */

#include <gtest/gtest.h>
#include <ros/time.h>
#include <QCoreApplication>
#include <QTimer>
#include <boost/thread/thread.hpp>
#include <ros/console.h>

void qtWorker(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.exec();
}

int main(int argc, char **argv)
{
  boost::thread* thr = new boost::thread(&qtWorker, argc, argv);
  ros::Time::init();
  while(NULL == QCoreApplication::instance())
  {
    ROS_INFO_STREAM_THROTTLE(0.1, "Waiting for QCore application to start");
  }
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
