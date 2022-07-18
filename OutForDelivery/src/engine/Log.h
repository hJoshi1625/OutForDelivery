#pragma once

#include <iostream>
#include <chrono>

class Log
{
public:

    enum Level : unsigned char
    {
        LevelTrace = 0,
        LevelInfo,
        LevelWarning,
        LevelError,
        LevelCritical
    };

public:

    Log(Level logLevel = LevelTrace)
        : m_logLevel(logLevel)
    {
        m_time = time(NULL);
        now = {};
    }

    void setLevel(Level level)
    {
        m_logLevel = level;
    }

    void trace(std::string message)
    {
        if (m_logLevel <= LevelTrace)
        {
            m_time = time(NULL);
            localtime_s(&now, &m_time);
            std::cout << "\x1B[37m"
                << "[" << (now.tm_hour) << ":" << (now.tm_min) << ":" << (now.tm_sec) << "] "
                << message
                << "\x1B[00m"
                << std::endl;
        }
    }

    void info(std::string message)
    {
        if (m_logLevel <= LevelInfo)
        {
            m_time = time(NULL);
            localtime_s(&now, &m_time);
            std::cout << "\x1B[32m"
                << "[" << (now.tm_hour) << ":" << (now.tm_min) << ":" << (now.tm_sec) << "] "
                << message
                << "\x1B[00m"
                << std::endl;
        }
    }

    void warning(std::string message)
    {
        if (m_logLevel <= LevelWarning)
        {
            m_time = time(NULL);
            localtime_s(&now, &m_time);
            std::cout << "\x1B[33m"
                << "[" << (now.tm_hour) << ":" << (now.tm_min) << ":" << (now.tm_sec) << "] "
                << message
                << "\x1B[00m"
                << std::endl;
        }
    }

    void error(std::string message)
    {
        if (m_logLevel <= LevelError)
        {
            m_time = time(NULL);
            localtime_s(&now, &m_time);
            std::cout << "\x1B[31m"
                << "[" << (now.tm_hour) << ":" << (now.tm_min) << ":" << (now.tm_sec) << "] "
                << message
                << "\x1B[00m"
                << std::endl;
        }
    }

    void critical(std::string message)
    {
        if (m_logLevel <= LevelCritical)
        {
            m_time = time(NULL);
            localtime_s(&now, &m_time);
            std::cout << "\x1B[43m\x1B[30m"
                << "[" << (now.tm_hour) << ":" << (now.tm_min) << ":" << (now.tm_sec) << "] "
                << message
                << "\x1B[00m"
                << std::endl;
        }
    }

private:
    Level m_logLevel;
    time_t m_time;
    struct tm now;

};

/*
    Name            FG  BG

    No Color          00

    Black           30  40
    Bright Black    90  100

    Red             31  41
    Bright Red      91  101

    Green           32  42
    Bright Green    92  102

    Yellow          33  43
    Bright Yellow   93  103

    Blue            34  44
    Bright Blue     94  104

    Magenta         35  45
    Bright Magenta  95  105

    Cyan            36  46
    Bright Cyan     96  106

    White           37  47
    Bright White    97  107
*/