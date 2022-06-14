for(i = 0; i < passLenght; i++){
        for(j = 0; j < 26; j++){
            if (specialCharacters[j] == password[i]){
                ctr += 1;
            }
        }
    }