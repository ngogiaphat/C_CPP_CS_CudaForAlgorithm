const rand = (from = 0, to = 10) => Math.floor(Math.random()*(to - from +1)) + from;
const start = (turn = 1, change = false) => {
    let correct = 0, incorrect = 0;
    for(let index = 0; index < turn; index++){
        let current = rand(1, 3);
        let choice = rand(1, 3);
        let showStatus = true;
        let changeStatus = false;
        do {
            show = rand(1, 3);
            if(show !== current && show !== choice)
                showStatus = false;
        }
        while(showStatus);
        if(change)
            do {
                temp = rand(1, 3);
                if(temp != show && temp != choice){
                    choice = temp;
                    changeStatus = true;
                }
            }
            while(changeStatus);
        if(choice == current)
            correct++;
        else
            incorrect++;
    };
    return {correct, incorrect};
};