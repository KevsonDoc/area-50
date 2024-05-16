import { Logger, Provider } from '@nestjs/common';
import { ConfigService } from '@nestjs/config';
import * as mongoose from 'mongoose';

export const databaseProviders: Provider[] = [
  {
    provide: 'DATABASE_CONNECTION',
    inject: [ConfigService],
    useFactory: (configService: ConfigService): Promise<typeof mongoose> => {
      Logger.log('Connecting to the database!');
      const connection = mongoose.connect(configService.get('DATABASE_URL'), {
        connectTimeoutMS: 2000,
      });
      Logger.log('Connected to the database!');
      return connection;
    },
  },
];
