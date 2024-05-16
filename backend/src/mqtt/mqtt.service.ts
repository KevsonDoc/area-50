import { Inject, Injectable, Logger } from '@nestjs/common';
import { Model } from 'mongoose';
import { DHT11SensorDto } from './dto/dht11-sensor.dto';

@Injectable()
export class MqttService {
  constructor(
    @Inject('SENSOR_MODEL')
    private sensorModel: Model<DHT11SensorDto>,
  ) {}

  public async insert(createMqttDto: DHT11SensorDto): Promise<void> {
    try {
      const sensorModel = new this.sensorModel(createMqttDto);
      await sensorModel.save();
      Logger.log('Sucess');
    } catch (error) {
      Logger.error(error);
    }
  }
}
