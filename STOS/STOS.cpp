#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;




int** zrobdzieci(int** tab, int indexojca, int pozycjaojca, int max) {
    for (int i = pozycjaojca; i < max + 1; i++)
    {

        if (tab[i][i] == indexojca + 1 && tab[i][0] == 0) {
            for (int j = 0; j < i; j++)
            {


                tab[j][i] = tab[j][pozycjaojca];
                tab[i][j] = tab[pozycjaojca][j];

                tab[j][i + 1] = tab[j][pozycjaojca];
                tab[i + 1][j] = tab[pozycjaojca][j];
                if (j == pozycjaojca) {
                    tab[j][i] = 1;
                    tab[i][j] = 1;
                    tab[j][i + 1] = 1;
                    tab[i + 1][j] = 1;
                }

                if (tab[j][pozycjaojca] == 0) {
                    tab[j][i] = 2;
                    tab[i][j] = 2;
                    tab[j][i + 1] = 2;
                    tab[i + 1][j] = 2;
                }
            }
            tab[i][i + 1] = 2;
            tab[i + 1][i] = 2;
            break;
        }
    }
    return tab;

}

struct vertex {
    int number = 0;
    bool brandNew = true;
    vertex* next = NULL;
};

void display(int** number, int up, int down) {
    cout << endl;
    for (int i = 0; i < up; i++)
    {
        cout << " " << i << "|";

    }cout << endl;
    for (int j = 0; j < down; j++)
    {


        for (int i = 0; i < up; i++)
        {

            if (number[i][j] > -1) {
                cout << " " << number[i][j] << "|";
            }
            else {
                cout << number[i][j] << "|";
            }
        }
        cout << endl;

    }
    char x;
    //cin >> x;
}
struct edge {
    int number;
    int v1;
    int v2;
    bool brandNew = true;
    edge* next = NULL;
};




struct slistEl
{
    slistEl* next = NULL;
    bool bottom = false;
    unsigned long v;
};



struct dane {
    int odleglosc;
    bool visited = false;
};



int max(int i, int j, int n, int** Matrix, int k);
slistEl** stworzGraf(int n);

dane* BFS(slistEl** A, int n, int start);

int wartoscbezwzgledna(int x) {
    if (x < 0) {
        return x * -1;
    }
    else
    {
        return x;
    }
}


int main()
{
    long int k, n;
    int s = -10;
    int** Z;

    int tabela[1022];
    for (int i = 0; i < 1022; i++)
        tabela[i] = -25;

    while (cin >> s) {
        switch (s) {

        case 0: {
            cin >> k;
            if (k < 0) {
                //wtf 
            }
            else
            {




                n = 1;


                if (k > 0)
                {
                    for (int i = 0; i < k; i++)
                        n = n * 3;
                }



                /*
                int m;
                if (k > 0)
                {
                        j = 1;
                        for (i = 0; i < k;i++) {
                                j = j * 2;
                                m = m * 3 + j;
                        }
                }
                */


                slistEl** A, ** B, ** C;
                slistEl* p, * r, * q, * t;


                A = new slistEl * [n];
                for (int i = 0; i < n; i++)
                    A[i] = NULL;



                if (k > 0) {


                    p = new slistEl;
                    p->v = 0;
                    p->bottom = true;
                    p->next = A[1];
                    A[1] = p;


                    p = new slistEl;
                    p->v = 0;
                    p->bottom = true;
                    p->next = A[2];
                    A[2] = p;

                }

                int nn = 3;


                while (nn < n) {
                    B = new slistEl * [nn];
                    C = new slistEl * [nn];


                    for (int i = 0; i < nn; i++)
                    {
                        B[i] = NULL;
                        C[i] = NULL;
                    }


                    for (int i = 0; i < nn; i++) {

                        p = A[i];
                        r = B[i];
                        q = C[i];
                        while (p)
                        {

                            r = new slistEl;
                            r->v = p->v + nn;
                            r->next = B[i];
                            B[i] = r;

                            if (p->bottom) {
                                t = new slistEl;
                                t->v = 0;
                                t->bottom = true;
                                t->next = B[i];
                                B[i] = t;
                            }


                            q = new slistEl;
                            q->v = p->v + 2 * nn;
                            q->next = C[i];
                            C[i] = q;

                            if (p->bottom) {
                                t = new slistEl;
                                t->v = 0;
                                t->bottom = true;
                                t->next = C[i];
                                C[i] = t;
                                p->bottom = false;
                            }


                            p = p->next;
                        }


                        A[i + nn] = B[i];
                        A[i + 2 * nn] = C[i];
                    }

                    delete[] B;
                    delete[] C;


                    nn = nn * 3;
                }



                Z = new int* [n];
                for (int i = 0; i < n; i++)
                    Z[i] = new int[n];


                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                        Z[i][j] = 0;
                }


                for (int i = 0; i < n; i++)
                {
                    p = A[i];
                    while (p)
                    {
                        Z[i][p->v] = 1;
                        p = p->next;
                    }
                }


                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                        if (Z[i][j] == 1)
                            Z[j][i] = 1;
                }


                for (int i = 0; i < n; i++)
                {
                    p = A[i];
                    while (p)
                    {
                        r = p;
                        p = p->next;
                        delete r;
                    }
                }
                for (int i = 0; i < n; i++) {
                    A[i] = NULL;
                }


                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (Z[i][j] == 1) {
                            p = new slistEl;
                            p->v = j;
                            p->next = A[i];
                            A[i] = p;
                        }
                    }
                }



                int suma = 0;
                for (int f = 0; f < n; f++) {
                    dane* tab = BFS(A, n, f);
                    for (int i = f; i < n; i++)
                        suma = suma + tab[i].odleglosc;
                    delete[] tab;
                }


                for (int i = 0; i < n; i++)
                {
                    p = A[i];
                    while (p)
                    {
                        r = p;
                        p = p->next;
                        delete r;
                    }
                }
                delete[] A;


                for (int i = 0; i < n; i++)
                {
                    delete[] Z[i];
                }
                delete[] Z;
                cout << suma << endl;
            }
        }
              break;

        case 11: {
            cin >> k;
            slistEl** A = stworzGraf(int(k));


            for (int z = 0; z < 100; z++) {
                z++;
            }




            if (tabela[k] == -25) {



                int suma = 0;
                for (int f = 0; f < k; f++) {



                    dane* tab = BFS(A, k, f);
                    for (int i = f; i < k; i++) {

                        suma = suma + tab[i].odleglosc;

                    }
                    delete[] tab;
                }

                tabela[k] = suma;
            }


            cout << tabela[k] << endl;


            slistEl* p, * r;
            for (int i = 0; i < k; i++)
            {
                p = A[i];
                while (p)
                {
                    r = p;
                    p = p->next;
                    delete r;
                }
            }
            delete[] A;
        }
               break;
        case 1:
        {
            // Lu Su go
            int krokomierz = 0;
            cin >> krokomierz;

            int ile_ma_byc = krokomierz;
            krokomierz = 2;
            int mno¿nik = 4;
            int czytyle = 3;
            while (czytyle < ile_ma_byc)
            {
                czytyle = czytyle + mno¿nik;
                krokomierz++;
                mno¿nik = mno¿nik * 2;
            }
            int odejmik = czytyle - ile_ma_byc;




            int lenghtt = 1;
            int potegowacz = 2;
            for (int i = 2; i < krokomierz + 1; i++)
            {
                lenghtt += potegowacz;
                potegowacz = potegowacz * 2;

            }
            //cout << potegowacz;
            //cout << "\n";
            //cout << lenghtt;
            //cout << "\n";
            int** tab = new int* [lenghtt];
            for (int i = 0; i < lenghtt; i++)
            {
                tab[i] = new int[lenghtt];

            }
            for (int i = 0; i < lenghtt; i++)
            {
                for (int j = 0; j < lenghtt; j++)
                {

                    tab[i][j] = 0;


                }
            }
            // k bedzie zapisany w ukosie
           // krok 0 i 1
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    tab[i][j] = 1;

                }
            }
            tab[0][0] = 0;
            tab[1][1] = -1;
            tab[2][2] = -1;
            // kroki 2 3 4 ..
            potegowacz = 2;
            int deep = -2;
            //display(tab, lenghtt, lenghtt);
            int ile = 4;
            int ile_wczeœniej = 3;
            int ileteraztworzymy = 2;
            for (int k = 2; k < krokomierz; k++)
            {

                for (int i = k - 1; i < lenghtt; i++)
                {
                    //cout << i;
                    // ka¿dy k -1 z nowymi wez³ami
                    if (tab[i][i] == deep + 1) {
                        for (int j = i; j < lenghtt; j++)
                        {
                            if (tab[j][j] == 0) {
                                tab[j][j] = deep;
                                tab[i][j] = 1;
                                tab[j][i] = 1;
                                tab[j + 1][j + 1] = deep;
                                tab[i][j + 1] = 1;
                                tab[j + 1][i] = 1;
                                // uwaga test
                                tab[j + 1][j] = 1;
                                tab[j][j + 1] = 1;

                                break;
                            }
                        }
                    }
                    //display(tab, lenghtt, lenghtt);
                    // ten popierdlony krok
                    if (tab[i][i] == deep) {

                        // szukamy przodka

                        int przodek = (i - 1) / 2;

                        //cout << przodek;
                        przodek = przodek % ((deep * -1) - 1);
                        //cout << przodek ;
                        int z = przodek;
                        tab[i][z] = 1;
                        tab[z][i] = 1;
                    }


                }

                deep--;
                //uzupe³nianie tabeli

                //										16 + 8 + 3 =27 
                for (int i = ile_wczeœniej; i < ile + ile_wczeœniej; i++)
                {
                    for (int j = 0; j < ile + ile_wczeœniej; j++)
                    {

                        if (i == 0 && j == i) { continue; }
                        int cel1 = 0;
                        int max1 = 100;
                        int cel2 = 0;
                        if (tab[i][j] == 0) {


                            for (int x = 0; x < ile_wczeœniej; x++)
                            {
                                if (tab[i][x] > 0) {
                                    if (tab[j][x] > 0) {
                                        if (tab[i][x] + tab[j][x] < max1) {
                                            max1 = tab[i][x] + tab[j][x];
                                        }
                                    }
                                }
                            }

                            tab[i][j] = max1;
                            tab[j][i] = max1;
                        }



                    }

                }
                ile_wczeœniej = ile_wczeœniej + ile;
                ile = ile * 2;
                //cout << ile;

            }

            //	cout << i;
                    //cout << "\n";


            for (int i = lenghtt - 1; odejmik > 0; i--)
            {
                for (int j = 0; j < lenghtt; j++)
                {
                    tab[i][j] = 0;
                    tab[j][i] = 0;
                }
                odejmik--;
            }


            // display(tab, lenghtt, lenghtt);
             //zliczanie 
            int licznik = 0;
            for (int i = 0; i < lenghtt; i++)
            {
                for (int j = 0; j < lenghtt; j++)
                {
                    if (tab[i][j] < 0) {
                        continue;
                    }
                    else {
                        licznik += tab[i][j];
                    }

                }
            }
            //display(tab, lenghtt, lenghtt);
            cout << licznik / 2;
            cout << "\n";

            display(tab, lenghtt, lenghtt);
            for (int i = 0; i < lenghtt; i++)
            {
                delete[] tab[i];

            }
            delete[]  tab;

        }
        break;
        case 4: {
            int lw;
            int ILE = 0;
            cin >> lw;
            // liczybui eile krokow
            int czytyle = 2;
            int mnoznik = 2;
            int krokomierz = 1;
            for (int i = 0; i < lw; i++)
            {
                if (czytyle + 1 >= lw) {
                    ILE = lw;
                    lw = czytyle + 1;
                    break;
                }
                else
                {
                    mnoznik = mnoznik * 2;
                    czytyle = czytyle + mnoznik;
                    krokomierz++;
                }
            }
            //  cout << krokomierz;

            int** tab;
            tab = new int* [lw];
            for (int i = 0; i < lw; i++)
            {
                tab[i] = new int[lw];
            }


            for (int i = 0; i < lw; i++)
            {
                for (int j = 0; j < lw; j++)
                {
                    tab[i][j] = 0;
                }
                if (i == 0) {
                    continue;
                }

            }
            // display(tab, lw, lw);



            int ile_jest_wiecholkow_po_jednej = (lw - 1) / 2;
            int index = 1;
            int ileteraz = 1;
            int gdziekurwajestesmy = 1;
            //cout << ile_jest_wiecholkow_po_jednej;
            //display(tab, lw, lw);
            int tam = 1;
            while (gdziekurwajestesmy <= ile_jest_wiecholkow_po_jednej) {
                for (int i = gdziekurwajestesmy; i <= tam; i++)
                {
                    tab[i][i] = index;

                }

                gdziekurwajestesmy = gdziekurwajestesmy + ileteraz;
                ileteraz = ileteraz * 2;
                tam = gdziekurwajestesmy + ileteraz;

                index++;



            }
            tab[ile_jest_wiecholkow_po_jednej + 1][ile_jest_wiecholkow_po_jednej + 1] = 0;
            // synowie i ojcowie
            tab[0][1] = 1;
            tab[1][0] = 1;
            if (lw > 3) {
                int idexojca = 1;
                int indexdziecka = 0;
                //display(tab, lw, lw);
                while (idexojca < ile_jest_wiecholkow_po_jednej - 1) {

                    for (int i = 0; i < ile_jest_wiecholkow_po_jednej; i++)
                    {
                        if (tab[i][i] == idexojca) {
                            tab = zrobdzieci(tab, idexojca, i, ile_jest_wiecholkow_po_jednej);
                            indexdziecka = idexojca + 1;
                        }
                    }

                    idexojca++;
                }
                // cout << ile_jest_wiecholkow_po_jednej;
                 // skopiowac tylko to gowno
                for (int i = ile_jest_wiecholkow_po_jednej + 1; i < lw; i++) {
                    for (int j = ile_jest_wiecholkow_po_jednej + 1; j < lw; j++)
                    {
                        tab[i][j] = tab[i - ile_jest_wiecholkow_po_jednej][j - ile_jest_wiecholkow_po_jednej];
                    }

                }
                for (int i = 0; i < lw; i++)
                {
                    for (int j = 0; j < lw; j++)
                    {
                        if (i == 0 || j == 0) {
                            tab[i][j] = 1;
                        }
                        if (tab[i][j] == 0) {
                            tab[i][j] = 2;
                        }
                    }
                }
                // aborcja dzieci
                if (indexdziecka > 2) {
                    indexdziecka--;
                }
                // cout << "INDEX idexdziecka :" << indexdziecka <<" xxxxxxxxxx ";
                ILE = lw - ILE;
                // cout << "ILE CHCEMY USUNAC " << ILE << " sssssssssss ";

                for (int i = lw - 1; i > 0; i--)
                {
                    if (ILE == 0) { break; }
                    if (tab[i][i] == indexdziecka) {
                        for (int j = 0; j < lw; j++)
                        {
                            tab[i][j] = 0;
                            tab[j][i] = 0;
                        }
                        ILE--;
                    }

                }

                //ZLICZANIEe
                tab[0][0] = 0;
                int wybik = 0;
                for (int i = 0; i < lw; i++)
                {
                    for (int j = 0; j < lw; j++)
                    {
                        if (j == i) {
                            continue;
                        }
                        wybik = wybik + tab[i][j];
                    }
                }
                cout << wybik / 2 << endl;;
            }
            else
            {
                cout << 4;
            }



            //  display(tab, lw, lw);






        }

              break;




        default:
        {
            return 0;
        }
        }
    }




    return 0;
}


slistEl** stworzGraf(int n) {


    int oooo = 10;



    vertex* v1, * v2, * v3, * vTemp, * vHead;

    slistEl** A;
    slistEl* p;


    int** M;
    M = new int* [n];
    for (int i = 0; i < n; i++)
        M[i] = new  int[n];

    int xyz = 0;
    string cos = "siema";







    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
        oooo++;
        xyz--;
    }




    v1 = new vertex;

    v1->brandNew = false;
    vHead = v1;





    v2 = new vertex;
    v2->number = 2;
    v2->next = vHead;
    vHead = v2;
    v3 = new vertex;
    v3->number = 1;
    v3->next = vHead;
    vHead = v3;

    M[0][1] = 1;
    M[1][0] = 1;
    M[0][2] = 1;
    M[2][0] = 1;
    M[1][2] = 1;
    M[2][1] = 1;

    int nn = 3;
    int kk = 1;











    while (nn < n) {

        vTemp = vHead;
        int index1;

        int index2;


        stack< vertex* > stos;




        while (vTemp && vTemp->brandNew == true && nn < n)
        {



            v1 = new vertex;
            v1->number = nn++;
            stos.push(v1);
            if (nn < n)
            {
                v2 = new vertex;
                v2->number = nn++;
                stos.push(v2);

                for (int z = 0; z < 100; z++) {
                    z++;
                }



                index1 = ((v1->number - 1) / 2) % kk;
                index2 = ((v2->number - 1) / 2) % kk;



                M[vTemp->number][v1->number] = 1;
                M[v1->number][vTemp->number] = 1;



                M[vTemp->number][v2->number] = 1;
                M[v2->number][vTemp->number] = 1;

                M[v1->number][v2->number] = 1;
                M[v2->number][v1->number] = 1;

                M[index1][v1->number] = 1;
                M[v1->number][index1] = 1;

                M[index2][v2->number] = 1;
                M[v2->number][index2] = 1;


                vTemp->brandNew = false;

                vTemp = vTemp->next;

            }
            else {

                index1 = ((v1->number - 1) / 2) % kk;

                M[vTemp->number][v1->number] = 1;
                M[v1->number][vTemp->number] = 1;
                M[index1][v1->number] = 1;
                M[v1->number][index1] = 1;

                vTemp->brandNew = false;
                vTemp = vTemp->next;

            }
        }




        kk++;



        while (!stos.empty()) {


            v1 = stos.top();
            stos.pop();
            v1->next = vHead;
            vHead = v1;
            vTemp = vHead;


        }

    }







    A = new slistEl * [n];

    for (int i = 0; i < n; i++)
        A[i] = NULL;


    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (M[i][j] == 1) {
                p = new slistEl;
                p->v = j;
                p->next = A[i];
                A[i] = p;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] M[i];
    }
    delete[] M;

    return A;
}


int max(int i, int j, int n, int** Matrix, int k) {




    int a1 = i / n;
    int b1 = i % n;
    int a2 = j / n;
    int b2 = j % n;
    if (k == 2) {

        if ((Matrix[a1][a2]) >= (Matrix[b1][b2]))
            return (Matrix[a1][a2]);
        else
            return  (Matrix[b1][b2]);
    }
    else {


        int m1 = max(a1, a2, n, Matrix, k - 1);
        int m2 = max(b1, b2, n, Matrix, k - 1);
        if (m1 >= m2)
            return m1;
        else
            return m2;
    }
}



dane* BFS(slistEl** A, int n, int start) {
    slistEl* p;
    dane* tab = new dane[n];
    for (int i = 0; i < n; i++) {
        tab[i].odleglosc = INT32_MAX;
    }
    tab[start].odleglosc = 0;
    tab[start].visited = true;
    queue<int> q;
    q.push(start);
    while (q.size() != 0) {
        int u = q.front();
        q.pop();

        p = A[u];
        while (p) {
            if ((p->v != u) && (tab[p->v].visited == false)) {
                tab[p->v].odleglosc = tab[u].odleglosc + 1;
                tab[p->v].visited = true;
                q.push(p->v);
            }
            p = p->next;
        }
    }
    return tab;
}
