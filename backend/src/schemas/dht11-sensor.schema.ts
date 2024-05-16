import * as mongoose from 'mongoose';

export const Dht11Schema = new mongoose.Schema({
  temperature: Number,
  humidity: Number,
  datetime: Date,
});
