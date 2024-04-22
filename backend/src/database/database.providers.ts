import { Provider } from '@nestjs/common';
import { ConfigService } from '@nestjs/config';
import * as mongoose from 'mongoose';

export const databaseProviders: Provider[] = [
  {
    provide: 'DATABASE_CONNECTION',
    inject: [ConfigService],
    useFactory: (configService: ConfigService): Promise<typeof mongoose> => {
      return mongoose.connect(configService.get('DATABASE_URL'));
    },
  },
];
