#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

int main() {
float hour , minute , second;
cout << "Hello & welcome to Auto-Shutdown program \n";
point:
cout << "Choose an option: 1) Shutdown 2) Log Out 3) Restart 4) Hibernate 5) Hybrid 6) Abort upcoming schedule\n";
int mode;
cin >> mode;
if (mode != 1 && mode != 2 && mode != 3 && mode != 4 && mode != 5 && mode != 6)
    {
    cout << "Invalid input.\n";
    goto point;
    }else if (mode == 6)
        {
            {
            ostringstream command;
            command << "shutdown /a > NUL 2> NUL";
            int result = system(command.str().c_str());
            if (result == 0)
            {
            cout << "Schedule aborted.\n";

            }else
            {
                cout << "There is no schedule\n";
            }
            goto point;
            }
        }else
    {
cout << "Arrange the time, the option will be executed after the time you arrange:\nHours:";
cin >> hour;
cout << "\nMinutes:\n";
cin >> minute;
cout << "Seconds\n";
cin >> second;
int shutdowntime = hour*3600 + minute*60 + second;
switch (mode) {
    case 1:
        {
        ostringstream command;
        command << "shutdown /s /t > NUL 2> NUL" << shutdowntime;
        cout << "Your computer will shutdown in " << hour << " h and " << minute << " min and " << second << " seconds\n";
        system(command.str().c_str());
        goto point;
        }
    case 2:
    {
        ostringstream command;
        command << "shutdown /l /t > NUL 2> NUL" << shutdowntime;
        cout << "Your computer will log out in " << hour << " h and " << minute << " min and " << second << " seconds\n";
        system(command.str().c_str());
        goto point;
    }
    case 3:
        {
        ostringstream command;
        command << "shutdown /r /t > NUL 2> NUL " << shutdowntime;
        cout << "Your computer will get restarted in " << hour << " h and " << minute << " min and " << second << " seconds\n";
        system(command.str().c_str());
        goto point;
        }
    case 4:
        {
        ostringstream command;
        command << "shutdown /h /t > NUL 2> NUL" << shutdowntime;
        cout << "Your computer will get hibernated in " << hour << " h and " << minute << " min and " << second << " seconds\n";
        system(command.str().c_str());
        goto point;
        }
    case 5:
        {
        ostringstream command;
        command << "shutdown /s /hybrid /t > NUL 2> NUL" << shutdowntime;
        cout << "Your computer will get hybridiated in " << hour << " h and " << minute << " min and " << second << " seconds\n";
        system(command.str().c_str());
        goto point;
        }

}
    }
}