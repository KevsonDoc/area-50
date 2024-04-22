import { Inject, Injectable, Logger } from '@nestjs/common';
import { Model } from 'mongoose';
import { DHT11SensorDto } from './dto/dht11-sensor.dto';

@Injectable()
export class MqttService {
  constructor(
    @Inject('SENSOR_MODEL')
    private catModel: Model<DHT11SensorDto>,
  ) {}

  public async insert(createMqttDto: DHT11SensorDto): Promise<void> {
    try {
      // const createdCat = new this.catModel(createMqttDto);
      // await createdCat.save();
      console.log(typeof createMqttDto);
      Logger.log('Sucess');
    } catch (error) {
      Logger.error(error);
    }
  }
}
