class Queue {
    constructor() {
        this._oldestIndex = 1;
        this._newestIndex = 1;
        this._storage = {};
    }

    size() {
        return this._newestIndex - this._oldestIndex;
    }

    enqueue(data) {
        this._storage[this._newestIndex] = data;
        this._newestIndex++;
    }

    dequeue() {
        let oldestIndex = this._oldestIndex;
        let newestIndex = this._newestIndex;
        let deletedData;

        if (oldestIndex !== newestIndex) {
            deletedData = this._storage.oldestIndex;
            delete this._storage.oldestIndex;
            this._oldestIndex++;

            return deletedData;
        }
    }
}
