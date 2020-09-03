#include "../includes/ranking.hpp"
#include "../libraries/sqlite/sqlite3.h"
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;

Ranking::Ranking(){
    char *err;
    int rc = sqlite3_open_v2("../data/2048.db", &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
    if(rc != SQLITE_OK){
        throw("Cannot create database");
    }
    string create_ranking_table_query = "CREATE TABLE IF NOT EXISTS ranking(points INT, nickname varchar(100));";
    rc = sqlite3_exec(db, create_ranking_table_query.c_str(), nullptr, nullptr, &err);
    if(rc != SQLITE_OK){
        throw("Cannot create ranking table");
    }
}

void Ranking::print_ranking(){
    vector<pair<string, int>> user_points = get_user_points();
    user_points = sort_ranking(user_points);
    printf("Ranking:\n");
    for(int i=0; i<min((int)user_points.size(), number_of_records); i++){
        cout << i+1 << ")" << user_points[i].first << " - " << user_points[i].second << endl;
    }
    printf("\nPressione enter para voltar para a tela inicial.\n");
    cin.ignore();
    cin.ignore();
}

vector<pair<string, int>> Ranking::sort_ranking(vector<pair<string, int>> user_points){
    auto sort_by_sec = [](const pair<string,int> &a, const pair<string,int> &b){ 
        return (a.second > b.second); 
    };
    sort(user_points.begin(), user_points.end(), sort_by_sec);
    return user_points;
}

vector<pair<string, int>> Ranking::get_user_points(){
    vector<pair<string, int>> user_points;
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "select points, nickname from ranking;", -1, &stmt, 0);
    int points;
    string name;
    sqlite3_step(stmt);
    while( sqlite3_column_text(stmt, 0)){
        points = sqlite3_column_int(stmt, 0);
        name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        user_points.push_back(make_pair(name, points));
        sqlite3_step(stmt);
    }
    return user_points;
}

bool Ranking::create_record(int points, string nickname){
    char *err;
    stringstream ss;
    // TODO: sqlite injection rsrsrsrsrsrs
    ss << "insert into ranking VALUES (" << points << ", '" << nickname << "');";
    string insert_user_points = ss.str();
    int rc = sqlite3_exec(db, insert_user_points.c_str(), nullptr, nullptr, &err);
    return rc == SQLITE_OK;
}