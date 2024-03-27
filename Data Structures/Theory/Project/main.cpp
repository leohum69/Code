#include "Headers.h"
using namespace std;

vector<vector<string> > s1;
vector<vector<string> > s2;
vector<bool> b1;
vector<graph> grap;
void displaybins()
{
    int counter = 1;
    for (int i = 0; i < grap.size(); i++)
        for (int j = 0; j < grap[i].arr.size() - 2; j++)
            cout << counter++ << " - " << grap[i].arr[j].head->data.first.name << " - " << grap[i].arr[j].head->data.first.pfull << endl;
    getch();
}
void bubbleSort(vector<pairstring> arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].second > arr[j + 1].second)
            {
                swappair(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // early stopping algorithm
        if (swapped == false)
            break;
    }
}

void checkbin(graph &g1, int x, string na)
{
    int idx = -1;
    if(na == "F-6"){
        idx = 0;
    }else if(na == "F-7"){
        idx = 1;
    }else if(na == "F-8"){
        idx = 2;
    }else if(na == "F-10"){
        idx = 3;
    }else if(na == "F-11"){
        idx = 4;
    }

    vector<location> v1;
    vector<int> index;
    for (int i = 0; i < g1.vert; i++)
    {
        if (g1.arr[i].head->data.first.pfull >= x)
        {
            v1.push_back(g1.arr[i].head->data.first);
            index.push_back(i);
        }
    }
    v1.push_back(g1.arr[10].head->data.first);
    index.push_back(10);
    v1.push_back(g1.arr[11].head->data.first);
    index.push_back(11);

    vector<vector<pairs> > pai;
    vector<pairs> pp;
    pairs temp;
    for (int i = 0; i < v1.size(); i++)
    {
        pp.push_back(pairs(v1[i], -1));
        for (int j = 0; j < v1.size(); j++)
        {
            if (i == j)
                continue;
            temp = g1.arr[index[i]].paor(v1[j].name);
            pp.push_back(temp);
        }
        pai.push_back(pp);
        pp.clear();
    }
    s1[idx].clear();
    graph g2;
    g2.insert(pai);
    string chkname = na;
    chkname.append(" Departure");
    string chkout = na;
    chkout.append(" Dumping");
    s1[idx].push_back(chkname);
    vector<pairstring> f1 = g2.dj_algo(chkname);

    bubbleSort(f1, f1.size());
    for (int i = 1; i < f1.size(); i++)
    {
        if (f1[i].first == chkname || f1[i].first == chkout)
        {
            continue;
        }
        s1[idx].push_back(f1[i].first);
    }
    s1[idx].push_back(chkout);
    // s1.push_back(add);
}
void checkbinupdated(graph &g1, int x, string na)
{
    int idx = -1;
    vector<location> v1;
    vector<int> index;
    for (int i = 0; i < g1.vert; i++)
    {
        if (g1.arr[i].head->data.first.pfull >= x)
        {
            v1.push_back(g1.arr[i].head->data.first);
            index.push_back(i);
        }
    }
    for (int i = 0; i < g1.vert; i++)
    {
        if (g1.arr[i].head->data.first.pfull < x)
        {
            g1.arr[i].head->data.first.setpfull(100); 
            v1.push_back(g1.arr[i].head->data.first);
            index.push_back(i);
            break;
        }
    }
    
    v1.push_back(g1.arr[10].head->data.first);
    index.push_back(10);
    v1.push_back(g1.arr[11].head->data.first);
    index.push_back(11);

    vector<vector<pairs> > pai;
    vector<pairs> pp;
    pairs temp;
    for (int i = 0; i < v1.size(); i++)
    {
        pp.push_back(pairs(v1[i], -1));
        for (int j = 0; j < v1.size(); j++)
        {
            if (i == j)
                continue;
            temp = g1.arr[index[i]].paor(v1[j].name);
            pp.push_back(temp);
        }
        pai.push_back(pp);
        pp.clear();
    }
    if(na == "F-6"){
        idx = 0;
    }
    if(na == "F-7"){
        idx = 1;
    }
    if(na == "F-8"){
        idx = 2;
    }
    if(na == "F-10"){
        idx = 3;
    }
    if(na == "F-11"){
        idx = 4;
    }
    s2[idx].clear();
    graph g2;
    g2.insert(pai);
    string chkname = na;
    chkname.append(" Departure");
    string chkout = na;
    chkout.append(" Dumping");

    string add;
    s2[idx].push_back(chkname);
    vector<pairstring> f1 = g2.dj_algo(chkname);
    bubbleSort(f1, f1.size());
    for (int i = 1; i < f1.size(); i++)
    {
        if (f1[i].first == chkname || f1[i].first == chkout)
        {
            continue;
        }
        s2[idx].push_back(f1[i].first);
    }
    s2[idx].push_back(chkout);
}
void showPath(vector<truckdriver> &v1, int idx)
{
    system("clear");
   
    cout << "*** Welcome Mr." << v1[idx].getname() << " ***\n" << endl;
    
    int x = v1[idx].getsector();
  
    if(s1[x].size() == 2)
    {
        cout<<"Controller has not assigned paths yet."<<endl;
        getch();
        return;
    }
    cout << "Your path for today is : \n" << endl;

    for (int i = 0; i < s1[x].size(); i++)
    {   if(i == s1[x].size() - 1)
            cout<<s1[x][i];
        else
            cout<<s1[x][i]<<" -> ";
    }
    cout<<endl;
    if(s2[x].size() != 0){
        cout<<"We found a new Bin aswell"<<endl;
        cout << "Your Updated path for today is : \n" << endl;
        for (int i = 0; i < s2[x].size(); i++)
        {
            if(i == s2[x].size() - 1)
                cout<<s2[x][i];
            else
                cout<<s2[x][i]<<" -> ";
        }
        
    }
    cout << "\n\nHave a nice day!" << endl;
    getch();
}
void livetrackin(int idx){
    system("clear");
    int time = (rand()%12) + 7;
    int min = 10;
    if(s2[idx].size() == 2 || s2[idx].size() == 0 || s1[idx].size()== 2 || s1[idx].size() == 0)
    {
        cout<<"Controllers have not assigned paths yet."<<endl;
        getch();
        return;
    }
    if(b1[idx] == 1){
        cout<<"The Update Path is "<<endl;
        for (int i = 0; s2[idx].size() > i; i++)
        {
            if(i == s2[idx].size() - 1)
                cout<<s2[idx][i];
            else
                cout<<s2[idx][i]<<" -> ";
        }
        string x;
        cout<<endl<<"Now live Tracking Starts"<<endl;
        x = to_string(time);
        x.append(" : ");
        x.append(to_string(min));
        x.append(" ");
        x.append(s2[idx][0]);
        x.append(" -> ");
        for (int i = 1; i < s2[idx].size() - 1; i++)
        {
            cout<<x;
            min += (rand()% 5) + 1;
            cout<<s2[idx][i]<<" Collected at "<<time<<" : "<<min<<" -> ";
            x.append(s2[idx][i]);
            x.append(" Collected at ");
            x.append(to_string(time));
            x.append(" : ");
            x.append(to_string(min));
            x.append(" -> ");
            for(int j = i+1 ; j < s2[idx].size(); j++){
                if(j == s2[idx].size()-1)
                    cout<<s2[idx][j];
                else    
                    cout<<s2[idx][j]<<" -> ";
            }
            cout<<endl<<endl;
            getch();
        }
        min += (rand()% 5) + 1;
        x.append(to_string(time));
        x.append(" : ");
        x.append(to_string(min));
        x.append(" ");
        x.append(s2[idx][s2[idx].size()-1]);
        cout<<x<<endl;           
    }else{
        for (int i = 0; s1[idx].size() > i; i++)
        {
            if(i == s1[idx].size() - 1)
                cout<<s1[idx][i];
            else
                cout<<s1[idx][i]<<" -> ";
        }
        string x;
        cout<<endl<<"Now live Tracking Starts"<<endl;
        x = to_string(time);
        x.append(" : ");
        x.append(to_string(min));
        x.append(" ");
        x.append(s1[idx][0]);
        x.append(" -> ");
        for (int i = 1; i < s1[idx].size() - 1; i++)
        {
            cout<<x;
            min += (rand()% 5) + 1;
            cout<<s1[idx][i]<<" Collected at "<<time<<" : "<<min<<" -> ";
            x.append(s1[idx][i]);
            x.append(" Collected at ");
            x.append(to_string(time));
            x.append(" : ");
            x.append(to_string(min));
            x.append(" -> ");
            for(int j = i+1 ; j < s1[idx].size(); j++){
                if(j == s1[idx].size()-1)
                    cout<<s1[idx][j];
                else    
                    cout<<s1[idx][j]<<" -> ";
            }
            cout<<endl<<endl;
            getch();
        }
        min += (rand()% 5) + 1;
        x.append(to_string(time));
        x.append(" : ");
        x.append(to_string(min));
        x.append(" ");
        x.append(s1[idx][s1[idx].size()-1]);
        cout<<x<<endl;
    }
     getch();  

}
void controllermenu(vector<controller> &v1, int idx)
{
    int cond;
    int thesh = 0;
    do
    {
        system("clear");
        cout << "*** Welcome to Controller " << v1[idx].getname() << " ***\n" << endl;
        cout << "1 - View Bin Data of All Areas" << endl;
        cout << "2 - Set ThreshHold and Send Notifications" << endl;
        cout << "3 - Check if any new bin got filled" << endl;
        cout << "4 - See Live Tracking" << endl;
        cout << "5 - Exit" << endl;
        cout << "\nEnter Choice : ";
        cin >> cond;
        cin.ignore();
        if (cond == 1)
            displaybins();
        else if (cond == 2)
        {
            system("clear");
            cout << "Enter the Value of ThreshHold: ";
            cin >> thesh;
            cin.ignore();
            checkbin(grap[0], thesh, "F-6");
            checkbin(grap[1], thesh, "F-7");
            checkbin(grap[2], thesh, "F-8");
            checkbin(grap[3], thesh, "F-10");
            checkbin(grap[4], thesh, "F-11");
            cout << "\nBins filled above " <<thesh<<"% are collectable today\nNotification have been sent to the drivers" << endl;
            getch();
        }else if(cond == 3)
        {   bool chk = 0;
            system("clear");
            if(rand()%10 == 1){
                cout<<"No new bins were Filled up"<<endl;
            }else{
                cout << "Enter the Value of ThreshHold: ";
                cin >> thesh;
                cin.ignore();
                if(rand()%2){
                    checkbinupdated(grap[0], thesh, "F-6");
                    cout<<"F-6 ";
                    b1[0] = 1;
                    chk = 1;
                }
                if(rand()%2){
                    checkbinupdated(grap[1], thesh, "F-7");
                    cout<<"F-7 ";
                    b1[1] = 1;
                    chk = 1;    
                }
                if(rand()%2){
                    checkbinupdated(grap[2], thesh, "F-8");
                    cout<<"F-8 ";
                    b1[2] = 1;
                    chk = 1;    
                }
                if(rand()%2){
                    checkbinupdated(grap[3], thesh, "F-10");
                    cout<<"F-10 ";
                    b1[3] = 1;
                    chk = 1;    
                }
                if(rand()%2){
                    checkbinupdated(grap[4], thesh, "F-11");
                    cout<<"F-11 ";
                    b1[4] = 1;
                    chk = 1;    
                }
                if(chk){
                    cout<<"Sectors got new bins to Collect, And the route has been Updated."<<endl;
                }else{
                    cout<<"No Sectors Got New Bins"<<endl;
                }
            }
            getch();
        }
        else if (cond == 4){
            int inp;
            system("clear");
            do
            {
                cout<<"Which Driver do you wanna see : "<<endl;
                cout<<"1 - F-6"<<endl;
                cout<<"2 - F-7"<<endl;
                cout<<"3 - F-8"<<endl;
                cout<<"4 - F-10"<<endl;
                cout<<"5 - F-11"<<endl;
                cout<<"6 - Exit"<<endl;
                cin>>inp;
                cin.ignore();
                if(inp == 6){
                    break;
                }
                livetrackin(inp-1);
            } while (inp != 6);
            
        }else if(cond == 5){
            break;
        }
    } while (cond != 5);
}

void logintruck(vector<truckdriver> &v1)
{
    cout << endl
         << endl;
    system("clear");
    cout << "*** TruckDriver Login Portal ***\n" << endl;
    string x;
    string y;
    cout << "Enter The username : ";
    cin.ignore();
    getline(cin, x);
    cout << "Enter the Password : ";
    getline(cin, y);
    int i = 0;
    for (i = 0; i < v1.size(); i++)
    {
        if (x == v1[i].getusrname())
        {
            if (y == v1[i].getpass())
            {
                break;
            }
        }
    }
    if (i == v1.size())
    {
        cout << "\nLogin Failed!" << endl;
        getch();
    }
    else
    {
        cout << "\nLogined Successfully" << endl;
        
        getch();
        showPath(v1, i);
    }
}
void registertruck(vector<truckdriver> &v1)
{
    system("clear");
    cout << "*** TruckDriver Register Portal ***" << endl;
    string x;
    string y;
    string z;
    cout << "\nEnter The Name for new user : ";
    cin.ignore();
    getline(cin, x);
    cout << "Enter the Username for new user : ";
    getline(cin, y);
    cout << "Enter the Password for new user : ";
    getline(cin, z);

    truckdriver t1(x, y, z, -1);
    v1.push_back(t1);
    ofstream out("truckdriver.csv");
    for (int i = 0; i < v1.size(); i++)
    {
        if (i != 0)
            out << endl;
        out << v1[i].getname() << "," << v1[i].getusrname() << "," << v1[i].getpass();
    }
    out.close();
    cout << "\nRegistered Successfully" << endl;
    
    getch();
}
void logincontrol(vector<controller> &v1)
{
    system("clear");
    cout << "*** Controller Login Portal ***\n" << endl;
    string x;
    string y;
    cout << "Enter The username : ";
    cin.ignore();
    getline(cin, x);
    cout << "Enter the Password : ";
    getline(cin, y);
    int i = 0;
    for (i = 0; i < v1.size(); i++)
    {
        if (x == v1[i].getusrname())
        {
            if (y == v1[i].getpass())
            {
                break;
            }
        }
    }
    if (i == v1.size())
    {
        cout << "\nLogin Failed!" << endl;
        getch();
    }
    else
    {
        cout << "\nLogined Successfully" << endl;
        getch();
        controllermenu(v1, i);
    }
}
void registercontrol(vector<controller> &v1)
{
    system("clear");
    cout << "*** Controller Register Portal ***\n" << endl;
    string x;
    string y;
    string z;
    cout << "Enter The Name for new Controller : ";
    cin.ignore();
    getline(cin, x);
    cout << "Enter the Username for new Controller : ";
    getline(cin, y);
    cout << "Enter the Password for new Controller : ";
    getline(cin, z);

    controller t1(x, y, z);
    v1.push_back(t1);
    ofstream out("controller.csv");
    for (int i = 0; i < v1.size(); i++)
    {
        if (i != 0)
            out << endl;
        out << v1[i].getname() << "," << v1[i].getusrname() << "," << v1[i].getpass();
    }
    out.close();
    cout << "\nRegistered Successfully" << endl;
    getch();
}
void truck()
{
    ifstream fin("truckdriver.csv");
    truckdriver t1;
    string c;
    int cond = -1;
    int i = 0;
    vector<truckdriver> v1;
    while (!fin.eof())
    {
        getline(fin, c, ',');
        t1.setname(c);
        getline(fin, c, ',');
        t1.setusrname(c);
        getline(fin, c);
        t1.setpass(c);
        t1.setsec(i++);
        v1.push_back(t1);
    }

    fin.close();
    do
    {
        system("clear");
        cout << "*** Truck Driver Dashboard ***\n" << endl;
        cout << "1 - Login" << endl;
        cout << "2 - Register" << endl;
        cout << "3 - Exit" << endl;
        cout << "\nEnter Choice : ";
        cin >> cond;
        if (cond == 1)
        {
            logintruck(v1);
        }
        else if (cond == 2)
        {
            registertruck(v1);
        }
        else if (cond == 3)
        {
            break;
        }

    } while (cond != 3);
}
void control()
{
    ifstream fin("controller.csv");
    controller t1;
    string c;
    int cond = -1;
    vector<controller> v1;
    while (!fin.eof())
    {
        getline(fin, c, ',');
        t1.setname(c);
        getline(fin, c, ',');
        t1.setusrname(c);
        getline(fin, c);
        t1.setpass(c);
        v1.push_back(t1);
    }

    fin.close();
    do
    {
        system("clear");
        cout << "*** Controller Dashboard ***\n" << endl;
        cout << "1 - Login" << endl;
        cout << "2 - Register" << endl;
        cout << "3 - Exit" << endl;
        cout << "\nEnter Choice : ";
        cin >> cond;
        if (cond == 1)
        {
            logincontrol(v1);
        }
        else if (cond == 2)
        {
            registercontrol(v1);
        }
        else if (cond == 3)
        {
            break;
        }

    } while (cond != 3);
}
void menu()
{
    int cond = -1;
    do
    {
        system("clear");
        cout << "*** Welcome to Waste Managemnet Dashboard ***" << endl
             << endl;
        cout << "1 - TruckDriver" << endl;
        cout << "2 - Bus Controller" << endl;
        cout << "3 - Exit" << endl;
        cin >> cond;
        if (cond == 1)
            truck();
        else if (cond == 2)
            control();
        else if (cond == 3)
            break;
    } while (cond != 3);
}
void read_locations(vector<vector<vector<pairs> > > &vv1)
{
    ifstream fin("FSector.csv");
    ifstream fil("Binfill.txt");
    vector<vector<pairs> > v1;
    for (int ppp = 0; ppp < 5; ppp++)
    {
        vector<int> dat;
        int lim = rand() % 72;
        // cout<<lim<<endl;
        for (int i = 0; i < 72; i++)
        {
            int pu;
            fil >> pu;
            fil.ignore();
            if (i == lim)
            {
                for (int j = 0; j < 50; j++)
                {
                    int pu;
                    fil >> pu;
                    dat.push_back(pu);
                    fil.ignore();
                }
                break;
            }
        }
        vector<pairs> tem;
        pairs p1;
        int count = 0;
        string x;
        int l;
        location temp;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                getline(fin, x, ',');
                temp.setname(x);
                fin >> l;
                fin.ignore();
                if (ppp == 0)
                    temp.setsector("F-6");
                if (ppp == 1)
                    temp.setsector("F-7");
                if (ppp == 2)
                    temp.setsector("F-8");
                if (ppp == 3)
                    temp.setsector("F-10");
                if (ppp == 4)
                    temp.setsector("F-11");
                if (x[0] == 'S')
                    temp.setisbin(0);
                else if (x[5] == 'e')
                    temp.setisbin(1);
                else
                {
                    temp.setisbin(2);
                }
                p1.first = temp;
                p1.second = l;

                tem.push_back(p1);
            }
            fin.ignore();
            if (i < 10)
                tem[0].first.pfull = dat[count++];
            v1.push_back(tem);
            tem.clear();
        }
        vv1.push_back(v1);
        v1.clear();
        dat.clear();
        count = 0;
    }
    fin.close();
    fil.close();
}
int main()
{
    s1.push_back(vector<string>());
    s1.push_back(vector<string>());
    s1.push_back(vector<string>());
    s1.push_back(vector<string>());
    s1.push_back(vector<string>());
    s2.push_back(vector<string>());
    s2.push_back(vector<string>());
    s2.push_back(vector<string>());
    s2.push_back(vector<string>());
    s2.push_back(vector<string>());
    b1.push_back(0);
    b1.push_back(0);
    b1.push_back(0);
    b1.push_back(0);
    b1.push_back(0);
    srand(time(0));
    vector<vector<vector<pairs> > > v1;
    read_locations(v1);
    for (int i = 0; i < 5; i++)
    {
        grap.push_back(graph());
        grap[i].insert(v1[i]);
    }
    menu();
    // checkbin(grap[0],75,"F-6");
    // checkbinupdated(grap[0],75,"F-6");
    // cout<<s1[0]<<endl;
    // cout<<s1[1]<<endl;

    // checkbin(grap[4],75,"F-11");
    // checkbinupdated(grap[4],75,"F-11");
    // b1[4] = 0;
    // livetrackin(4);
    return 0;
}