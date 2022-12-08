#!/usr/bin/python3
""" DATABASE for AirBnB"""
from os import getenv
from sqlalchemy import create_engine, MetaData
from sqlalchemy.orm import sessionmaker, scoped_session
from models.base_model import BaseModel, Base
#from models.amenity import Amenity
from models.city import City
#from models.place import Place
#from models.review import Review
from models.state import State
#from models.user import User
import models


class DBStorage:
    """DBStorage hbnb_dev"""

    __engine = None
    __session = None

    def __init__(self):
        """ create the engine"""
        user = getenv("HBNB_MYSQL_USER")
        password = getenv("HBNB_MYSQL_PWD")
        host = getenv("HBNB_MYSQL_HOST")
        database = getenv("HBNB_MYSQL_DB")
        env = getenv("HBNB_ENV")

        self.__engine = create_engine("mysql+mysqldb://{}:{}@{}/{}".format(user, password, host, database), pool_pre_ping=True)

        if env == "test":
            Base.metadata.drop_all(self.__engine)
    def all(self, cls=None):
        """query on the current database session (self.__session)
        all objects depending of the class name (argument cls)"""
    
        queried_dict = {}
        if cls:
            if type(cls) == str:
                cls = eval(cls)
        query = self.__session.query(cls).all()
        for elem in query:
            key = "{}.{}".format(type(elem).__name__, elem.id)
            queried_dict[key] = elem

        else:
            obj = {'State': State, 'City': City} #, 'User': User, 'Place': Place}
            for key, value in obj.items():
                query = self.__session.query(value).all()
                for elem in query:
                key = "{}.{}".format(type(elem).__name__, elem.id)
                queried_dict[key] = elem

        return queried_dict

    def mew(self, obj):
        """add the object to the current database session"""
        self.__session.add(obj)

    def save(self):
        """commit all changes"""
        self.__session.commit()

    def delete(self, obj=None):
        """delete from the current database session obj if not None"""
        if obj:
            self.__session.delete(obj)

    def reload(self):
        """create all tables in the database"""
        Base.metadata.create_all(self.__engine)

        factory_s = sessionmaker(bind=self.__engine, expire_on_commit=False)

        Session = scoped_session(factory_s)

        self.__engine = Session()
