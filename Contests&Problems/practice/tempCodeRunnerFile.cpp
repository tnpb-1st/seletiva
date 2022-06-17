    if(sol_found) {
        cout << 'Y' << endl;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << best_state[i][j];
            }
            cout << endl;
        }
    } else {
        cout << 'N';
    }