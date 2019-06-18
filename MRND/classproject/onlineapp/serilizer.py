from rest_framework import routers, serializers, viewsets
from onlineapp.models import *
class CollegeSerializer(serializers.ModelSerializer):
    class Meta:
        model=College
        fields=('name','location','acronym','contact')


class MockTest1Serializer(serializers.ModelSerializer):
    class Meta:
        model=MockTest1
        fields=('problem1','problem2','problem3','problem4','total')

class StudentSerializer(serializers.ModelSerializer):
    #college=serializers.RelatedField(read_only=False)
    class Meta:
        model=Student
        fields=('name','email','db_folder','dropped_out')


class CollegeInformationSerializer(serializers.ModelSerializer):
    student=StudentSerializer(many=False,read_only=False)
    class Meta:
        model=MockTest1
        fields=['problem1','problem2','problem3','problem4','total','student']
    def create(self, validated_data):
        student_validate=validated_data.pop('student')
        student_validate['college']=College.objects.get(id=self.context['id'])
        s=Student.objects.create(**student_validate)
        m=MockTest1.objects.create(student=s,**validated_data)
        return m

    def update(self,instance,validated_data):
        student_validate=validated_data.pop('student')

        instance.problem1=validated_data.get('problem1', instance.problem1)
        instance.problem2 = validated_data.get('problem2', instance.problem2)
        instance.problem3 = validated_data.get('problem3', instance.problem3)
        instance.problem4 = validated_data.get('problem4', instance.problem4)
        instance.total = validated_data.get('total', instance.total)

        s=Student.objects.get(id=self.context['sid'])
        s.name=student_validate['name']
        s.email = student_validate['email']
        s.db_folder = student_validate['db_folder']
        s.dropped_out = student_validate['dropped_out']
        s.save()
        instance.student=s

        instance.save()
        return instance





