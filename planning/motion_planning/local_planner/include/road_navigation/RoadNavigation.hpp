/* 
 * File:   RoadNavigation.hpp
 * Author: satya
 *
 * Created on December 13, 2013, 7:37 PM
 */

#ifndef ROADNAVIGATION_HPP
#define	ROADNAVIGATION_HPP

#include <Header.hpp>
#include <geometry_msgs/PoseStamped.h>
#include "road_navigation/Trajectory.hpp"
#include "utils/Pose2D.hpp"

namespace navigation {

    class RoadNavigation {
    public:
        RoadNavigation();
        RoadNavigation(const RoadNavigation& orig);
        virtual ~RoadNavigation();

        nav_msgs::Path planRoadDetection(const nav_msgs::Path::ConstPtr& lane_traj, const geometry_msgs::PoseStamped::ConstPtr& pose);

    private:
        int num_targets;
        double spacing;
        double target_lookahead;
        std::vector<nav_msgs::Path*> paths;

        nav_msgs::Path convertToNavMsgsPath(Trajectory& trajectory);
        nav_msgs::Path decideTargetTrajectory(nav_msgs::Path::ConstPtr lane_traj);
        double getDistance(geometry_msgs::Pose& pose1, geometry_msgs::Pose& pose2);
        std::vector<geometry_msgs::Pose> getTargets(geometry_msgs::Pose current_pose, nav_msgs::Path target_traj);
        std::vector<nav_msgs::Path> getPaths(geometry_msgs::Pose current_pose, std::vector<geometry_msgs::Pose> targets);
    };
}
#endif	/* ROADNAVIGATION_HPP */
