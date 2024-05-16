import { Connection } from 'mongoose';
import { Dht11Schema } from '../schemas/dht11-sensor.schema';

export const mqttProviders = [
  {
    provide: 'SENSOR_MODEL',
    useFactory: (connection: Connection) =>
      connection.model('SENSOR', Dht11Schema),
    inject: ['DATABASE_CONNECTION'],
  },
];
