#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <ctime>

using namespace std;

class clsQueueLine
{
private:
    string _QueueLinePrefix = " ";
    short _TimePerCustormer = 0;
    short _TotalTickets = 0;
    class _clsTicket
    {
    private:
        int _TicketNumber = 0;
        string _Prefix;
        string _TicketTimeStamp;
        short _WaitingClients = 0;
        short _TimePerClient = 0;
        short _ExpectedServeTime = 0;

        string _GetTimeStamp()
        {
            time_t t = time(0);
            tm *now = localtime(&t);
            short Year, Month, Day;
            Year = now->tm_year + 1900;
            Month = now->tm_mon + 1;
            Day = now->tm_mday;
            short Hour, Min, Sec;
            Hour = now->tm_hour;
            Min = now->tm_min;
            Sec = now->tm_sec;
            return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Min) + ":" + to_string(Sec));
        }

    public:
        _clsTicket(string Prefix, short Number, short WaitingClients, short AverageServingTime)
        {
            _Prefix = Prefix;
            _TicketNumber = Number;
            _TicketTimeStamp = _GetTimeStamp();
            _WaitingClients = WaitingClients;
            _TimePerClient = AverageServingTime;
        }

        string Prefix() const
        {
            return _Prefix;
        }

        short Number()
        {
            return _TicketNumber;
        }

        string FullTicketNumber() const
        {
            return _Prefix + to_string(_TicketNumber);
        }

        short WaitingClients()
        {
            return _WaitingClients;
        }

        short ExpectedServingTime()
        {
            return _WaitingClients * _TimePerClient;
        }

        void Print()
        {
            cout << "\t\t\t\t\t--------------------------\n";
            cout << "\t\t\t\t\t\t   " << FullTicketNumber() << "\n\n";
            cout << "\t\t\t\t\t  " << _TicketTimeStamp << endl;
            cout << "\t\t\t\t\t  Waiting Clietns = " << _WaitingClients << endl;
            cout << "\t\t\t\t\t    Surving Time in\n";
            cout << "\t\t\t\t\t      " << ExpectedServingTime() << " Minutes.\n";
            cout << "\t\t\t\t\t--------------------------\n\n";
        }
    };
    queue<_clsTicket> _TicketsQueue;

public:
    clsQueueLine(string Prefix, short Time)
    {
        _QueueLinePrefix = Prefix;
        _TimePerCustormer = Time;
        _TotalTickets = 0;
    }

    void IssueTicket()
    {
        _TotalTickets++;
        _clsTicket NewTicket(_QueueLinePrefix, _TotalTickets, WiatingClients(), _TimePerCustormer);
        _TicketsQueue.push(NewTicket);
    }

    short WiatingClients()
    {
        return _TicketsQueue.size();
    }

    string WhoIsNext()
    {
        if (_TicketsQueue.empty())
            return "No Clients Left.";
        else
            return _TicketsQueue.front().FullTicketNumber();
    }

    bool ServeNextClient()
    {
        if (_TicketsQueue.empty())
            return false;
        else
        {
            _TicketsQueue.pop();
            return true;
        }
    }

    short ServedClients()
    {
        return _TotalTickets - WiatingClients();
    }

    void PrintTicketsLineRTL()
    {
        if (_TicketsQueue.empty())
            cout << "\n\t\tTickets: No Tickets.";
        else
        {
            queue<_clsTicket> TempQueue = _TicketsQueue;
            cout << "\n\t\tTickets: ";
            while (!TempQueue.empty())
            {
                cout << TempQueue.front().FullTicketNumber() << " <--- ";
                TempQueue.pop();
            }
            cout << "\n";
        }
    }

    void PrintTicketsLineLTR()
    {
        if (_TicketsQueue.empty())
            cout << "\n\t\tTickets: No Tickets.";
        else
        {
            queue<_clsTicket> TempQueue = _TicketsQueue;
            stack<_clsTicket> ReversedTempStack;
            while (!TempQueue.empty())
            {
                ReversedTempStack.push(TempQueue.front());
                TempQueue.pop();
            }

            cout << "\n\t\tTickets: ";
            while (!ReversedTempStack.empty())
            {
                cout << ReversedTempStack.top().FullTicketNumber() << " ---> ";
                ReversedTempStack.pop();
            }
            cout << "\n";
        }
    }

    void PrintInfo()
    {
        cout << "\t\t\t\t\t--------------------------\n";
        cout << "\t\t\t\t\t\tQueue Info\n";
        cout << "\t\t\t\t\t--------------------------\n";
        cout << "\t\t\t\t\t   Prefix          = " << _QueueLinePrefix << endl;
        cout << "\t\t\t\t\t   Total Tickets   = " << _TotalTickets << endl;
        cout << "\t\t\t\t\t   Surved Clients  = " << ServedClients() << endl;
        cout << "\t\t\t\t\t   Waiting Clietns = " << WiatingClients() << endl;
        cout << "\t\t\t\t\t--------------------------\n\n";
    }

    void PrintAllTickets()
    {
        cout << "\n\t\t\t\t\t     ---Tickets---\n";
        if (_TicketsQueue.empty())
            "\n\t\t\t\t\t     --- No Tickets ---\n";
        else
        {
            queue<_clsTicket> TempQueue = _TicketsQueue;
            while (!TempQueue.empty())
            {
                auto Ticket = TempQueue.front();
                Ticket.Print();
                TempQueue.pop();
            }
        }
    }
};