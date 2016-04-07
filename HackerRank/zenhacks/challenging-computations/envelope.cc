while (dq.size() >= 3 &&
                (dq[0].S - dq[1].S) * (dq[2].F - dq[1].F) >= (dq[1].S - dq[2].S) * (dq[1].F - dq[0].F)) {
    dq[1] = dq[0];
    dq.pop_front();
}
// while (p >= 3 &&
//                 (dq[p-3].S - dq[p-2].S) * (dq[p-1].F - dq[p-2].F) >= (dq[p-2].S - dq[p-1].S) * (dq[p-2].F - dq[p-3].F)) {
//     dq[p-2] = dq[p-1];
//     p--;
// }


while (SZ(dq) >= 2 && eval(dq[0], M[i].q) >= eval(dq[1], M[i].q)) {
    dq.pop_front();
}
