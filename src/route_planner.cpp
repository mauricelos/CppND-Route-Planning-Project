#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel& model, float start_x, float start_y, float end_x, float end_y) : m_Model(model)
{
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

    start_node = &m_Model.FindClosestNode(start_x, start_y);
    end_node = &m_Model.FindClosestNode(end_x, end_y);

    start_node->visited = true;
    open_list.push_back(start_node);
}

float RoutePlanner::CalculateHValue(const RouteModel::Node* node)
{
    node->distance(*end_node);
}

void RoutePlanner::AddNeighbors(RouteModel::Node* current_node)
{
    current_node->FindNeighbors();
    for (auto neighbor : current_node->neighbors)
    {
        neighbor->parent = current_node;
        neighbor->h_value = CalculateHValue(neighbor);
        neighbor->g_value = current_node->g_value + current_node->distance(*neighbor);
        neighbor->visited = true;
        open_list.push_back(neighbor);
    }
}

RouteModel::Node* RoutePlanner::NextNode()
{
    auto comparator = [](RouteModel::Node* lhs, RouteModel::Node* rhs) {
        return (lhs->g_value + lhs->h_value) < (rhs->g_value + rhs->h_value);
    };

    auto next_node_it = std::min_element(open_list.begin(), open_list.end(), comparator);
    auto next_node = *next_node_it;
    open_list.erase(next_node_it);

    return next_node;
}

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node* current_node)
{
    distance = 0.0f;
    std::vector<RouteModel::Node> path_found{*current_node};

    while (current_node != start_node)
    {
        distance += current_node->distance(*current_node->parent);
        current_node = current_node->parent;
        path_found.push_back(*current_node);
    }

    std::reverse(path_found.begin(), path_found.end());

    distance *= m_Model.MetricScale();
    return path_found;
}

void RoutePlanner::AStarSearch()
{
    while (!open_list.empty())
    {
        RouteModel::Node* current_node = NextNode();

        if (current_node == end_node)
        {
            m_Model.path = ConstructFinalPath(end_node);
            break;
        }

        AddNeighbors(current_node);
    }
}