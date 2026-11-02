#pragma once
#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
#include"clsDate.h"

using namespace std;

class clsQueueLine
{
	string _Prefix;
	int _AverageServeTime;
	int _TotalTickts = 0;

	class  clsTicket
	{
	private:
		int _Number = 0;
		string _Prefix;
		string _TicketTime;
		short _WaitingClients = 0;
		short _AverageServeTime = 0;
		short _ExpectedServeTime = 0;

	public:
		clsTicket(string Prefix, short Number, short WaitingClients, short AverageExpectedTiem)
		{
			_Number = Number;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageExpectedTiem;
			_Prefix = Prefix;
		}

		string Prefix()
		{
			return _Prefix;
		}

		short Number()
		{
			return _Number;
		}

		string FullNumber()
		{
			return _Prefix + to_string(_Number);
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		short WiatingClients()
		{
			return _WaitingClients;
		}

		short ExpectedServeTime()
		{
			return _AverageServeTime * WiatingClients();
		}

		void Print()
		{
			cout << "\n" << setw(45) << "" << "__________________________________\n\n";

			cout << setw(47) << "" << left << setw(18) << _Prefix<< "\n";
			cout << setw(47) << "" << left << setw(18) << _TicketTime << "\n";
			cout << setw(47) << "" << "Wating Clients: " << _WaitingClients<< "\n";
			cout << setw(47) << "" << ExpectedServeTime() << " Minutes\n";

			cout << setw(45) << "" << "__________________________________\n";

		}
	
	};

	

public:

	queue<clsTicket> QueueLine;

	clsQueueLine(string Prefix, int AverageServeTime)
	{
		_Prefix = Prefix;
		_TotalTickts = 0;
		_AverageServeTime = AverageServeTime;
	}

	void IssueTicket()
	{
		_TotalTickts++;
		clsTicket Ticket(_Prefix, _TotalTickts, WaitingClients(), _AverageServeTime);

		QueueLine.push(Ticket);

	}

	short WaitingClients()
	{
		return QueueLine.size();
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
		{
			return "NO Clients Left.";
		}
		else
			return QueueLine.front().FullNumber();
	}

	
	void PrintInfo()
	{
		cout << "\n" << setw(45) << "" << "__________________________________";
		cout << "\n" << setw(55) << "" << "Queue Info";
		cout << "\n" << setw(45) << "" << "__________________________________\n\n";

		cout << setw(47) << "" << left << setw(18) << "Prefix          = " << _Prefix << "\n";
		cout << setw(47) << "" << left << setw(18) << "Total Tickets   = " << _TotalTickts << "\n";
		cout << setw(47) << "" << left << setw(18) << "Served Clients  = " << ServedClients() <<  "\n";
		cout << setw(47) << "" << left << setw(18) << "Waiting Clients = " << QueueLine.size() << "\n";

		cout << setw(45) << "" << "__________________________________\n";

	}


	bool ServeNextClient()
	{
		if (QueueLine.empty())
		{
			return false;
		}
		else
			QueueLine.pop();

		return true;
	}

	short ServedClients()
	{
		return _TotalTickts - WaitingClients();
	}

	void PrintTicketsLineRTL()
	{
		if (!QueueLine.empty())
		{
			queue<clsTicket> TempQueue = QueueLine;

			cout << "\n";

			while (!TempQueue.empty())
			{
				cout << TempQueue.front().FullNumber() << " <--";

				 TempQueue.pop();
			}
		}
	}

	void PrintTicketsLineLTR()
	{
		cout << "\n";
		if (!QueueLine.empty())
		{
			queue<clsTicket> TempQueue = QueueLine;

			stack<clsTicket> TmepStackLine;

			while (!TempQueue.empty())
			{
				TmepStackLine.push(TempQueue.front());

				TempQueue.pop();
			}

			while (!TmepStackLine.empty())
			{
				cout << TmepStackLine.top().FullNumber() << " -->";

				TmepStackLine.pop();
			}
			cout << "\n";
		}

		
	}

	void PrintAllTickets()
	{
		cout << "\n\n\t\t\t     ---Tickets---";

		if (QueueLine.empty())
		{
			cout << "\n\n\t\t\t     ---No Tickets---\n";
		}

		queue<clsTicket> TempQueueLine = QueueLine;
		while(!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}
	}

};

