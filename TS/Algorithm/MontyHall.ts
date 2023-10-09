// @ts-nocheck
const rand = (from: number = 0, to: number = 10): number => Math.floor(Math.random()*(to - from + 1)) + from;
const start = (turn: number = 1, change: boolean = false): {
    correct: number,
    incorrect: number
} => {
    let correct: number = 0, incorrect: number = 0;
    for(let index: number = 0; index < turn; index++){
        let current: number = rand(1, 3);
        let choice: number = rand(1, 3);
        let showStatus: boolean = true;
        let changeStatus: boolean = false;
        do {
            let show: number = rand(1, 3);
            if(show !== current && show !== choice)
                showStatus = false;
        }
        while(showStatus);
        if(change)
            do {
                let temp: number = rand(1, 3);
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